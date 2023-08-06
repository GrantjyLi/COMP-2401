#include "ServerConnect.h"
#include "Pokemon.h"

int getSocket(){
    int mySocket;
    int status;
    struct sockaddr_in serverAddr;

    // Create socket
    mySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(mySocket < 0){printf("*** CLIENT ERROR: Could open socket.\n");exit(-1);}

    // Setup address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons((unsigned short)SERVER_PORT);

    status = connect(mySocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if(status < 0){printf("Couldn't connect to server\n");exit(-1);}

    return mySocket;
}

void *sendData(void *dataIn){
    SharedData *data = (SharedData*)dataIn;
    size_t dataSize;
    char *buffer;
    int bytesReceived;

    send(data->clientSocket, &(data->flag), sizeof(char), 0);

    dataSize = strlen(data->pokeType);
    //sending type of Pokemon to search for
    send(data->clientSocket, &dataSize, sizeof(size_t), 0);
    send(data->clientSocket, data->pokeType, strlen(data->pokeType), 0);

    bytesReceived = recv(data->clientSocket, &dataSize, sizeof(size_t), 0);
    if(bytesReceived < 0){printf("Couldn't recieve server data size.\n");return NULL;}

    buffer = (char*)malloc(dataSize); //buffer to take in data from server

    bytesReceived = recv(data->clientSocket, buffer, dataSize, 0); //receiving data
    if(bytesReceived < 0){printf("Couldn't recieve server data.\n");return NULL;}

    //printf("BS: %ld, DS: %ld",strlen(buffer), dataSize);
    
    pthread_mutex_lock(&(data->mutex)); //locking mutex
    
    data->deckSize += dataSize;
    data->pokeDeck = realloc(data->pokeDeck, data->deckSize);//memory issue??? // increasing pokeDeck size
    
    memcpy(data->pokeDeck + data->deckSize - dataSize, buffer, dataSize);

    pthread_mutex_unlock(&(data->mutex));//unlocking mutex

    free(buffer);
}