#include "Search.h"

char * getReadFile(){

    char * fileName;
     //getting user input
    printf("Input is case sensitive and include file suffix. i.e: \"Test.txt\"\n");
    printf("Enter destination file name: ");
    scanf("%m[^\n]", &fileName);

    FILE * fp = fopen(fileName, "r");
    while(fp == NULL){ // if not a valid file, loop until valid file or exit
        free(fileName);
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %m[^\n]", &fileName);

        if(fileName[0] =='n'){ //exiting after freeing data 
            printf("Program exiting...");
            free(fileName);
            return 0;
        }
        fp = fopen(fileName, "r");
    }
    fclose(fp);

    return fileName;
}

int main() {
    //server & client variables
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int status, bytesReceived, addrSize;
    
    // Create the server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket < 0) {printf("*** SERVER ERROR: Could not open socket.\n");exit(-1);}
    
    // Setup the server address
    memset(&serverAddr, 0, sizeof(serverAddr)); // zeros the struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons((unsigned short) SERVER_PORT);
    
    // Bind the server socket
    status = bind(serverSocket,(struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (status < 0) {printf("*** SERVER ERROR: Could not bind socket.\n");exit(-1);}
    
    // Wait for clients now
    status = listen(serverSocket, 5);
    if (status < 0) {printf("*** SERVER ERROR: Could not listen socket.\n");exit(-1);}
    addrSize = sizeof(clientAddr);

    char *readFile = getReadFile();
    while (1) {

        clientSocket = accept(serverSocket,(struct sockaddr *)&clientAddr, &addrSize);
        if (clientSocket < 0) {printf("*** SERVER ERROR: Could not accept socket.\n");exit(-1);}

        printf("SERVER: Recieved client connection.\n");

        //client input variables
        char *pokeType = (char *)malloc(0);
        char *pokeDeck;
        size_t size;
        char flag;
        while (1) { // Timeout occurred, no client ready
            pokeDeck = (char*)malloc(0);

            //IMPLEMENT STOP CONDITION
            bytesReceived = recv(clientSocket, &flag, sizeof(char), 0);
            if(flag == 1){
                printf("SERVER: Client finished.\n");
                break;}

            //getting type of Pokemon to search for
            bytesReceived = recv(clientSocket, &size, sizeof(size_t), 0);
            if (bytesReceived < 0) {printf("SERVER: Could not recieve client source file size.");exit(-1);}
            
            pokeType = realloc(pokeType, size +1);
            bytesReceived = recv(clientSocket, pokeType, size, 0);

            if (bytesReceived < 0) {printf("SERVER: Could not recieve client Pokemon type.");free(pokeType);exit(-1);}
            pokeType[size] = '\0';
            printf("SERVER: Received client Pokemon type: %s\n", pokeType);

            //search for the pokemon
            pokeDeck = getPokemon(readFile, pokeType, pokeDeck);


        FILE * fname = fopen("Shit.txt", "w");
        fprintf(fname, "%s", pokeDeck);
        fclose(fname);


            printf("SERVER: Finished search for type: %s\n", pokeType);
            size = strlen(pokeDeck);
            
            //return number of pokemon found and a string of all them
            send(clientSocket, &size, sizeof(size_t), 0);
            send(clientSocket, pokeDeck, size, 0);
            printf("SERVER: Sent searched data for type: %s\n", pokeType);

            free(pokeDeck);
        }
        free(pokeType);
        free(readFile);
        close(clientSocket);
        if(flag == 1)break;
    }

    close(serverSocket);
    printf("SERVER: Shutting down.\n");
}