#include "Pokemon.h"
#include "ServerConnect.h"

void *savePokemon(void *dataIn);
int menu(SharedData data);
void freedata(SharedData* data);

void *savePokemon(void *dataIn){ // function to write a file with all indexed pokemon's data
    
    //creating data pointer variable to access attributes
    SharedData *data = (SharedData*)dataIn;

    pthread_mutex_lock(&(data->mutex)); //locking mutex

    // char line[100];
    // int linesSize =0;
    // char pokeName[25], pokeType1[10], pokeType2[10], legendStatus;
    // int pokeNum, pokeTotal, hp, attack, sAttack, defence, sDefence, speed;
    // char gen;

    FILE *shitFile = fopen(data->writeFileName, "w");
    fprintf(shitFile, "%s\n", data->pokeDeck);
    fclose(shitFile);

    // //creating and looping through new user file
    //FILE *saveFile = fopen(data->writeFileName, "w");
    //while(sscanf(data->pokeDeck + linesSize, "%[^\n]", line) > 0){
        //fprintf(saveFile, "%s\n", line);

        // pokeType2[0] = '\0'; // avoiding using last type2 if current one doesn't exit

        // if(data->flag == 1) return NULL; // closing thread
        //linesSize += strlen(line) +1;

        // sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%c,%1[^,]\n",
        //           &pokeNum,
        //           pokeName,
        //           pokeType1,
        //           pokeType2,
        //           &pokeTotal,
        //           &hp,
        //           &attack,
        //           &defence,
        //           &sAttack,
        //           &sDefence,
        //           &speed,
        //           &gen,
        //           &legendStatus);

        
        // //writing each pokemon indexed in a format
        // fprintf(saveFile, "Pokemon: #%d - %s", pokeNum, pokeName);
        // fprintf(saveFile, "\nPokemon Types: %s - %s", pokeType1, pokeType2);
        // fprintf(saveFile, "\nPokemon Total: %d", pokeTotal);
        // fprintf(saveFile, "\nPokemon HP: %d", hp);
        // fprintf(saveFile, "\nPokemon Attack & Defence: %d - %d", attack, defence);
        // fprintf(saveFile, "\nPokemon Special Attack & Defence: %d - %d", sAttack,  sDefence);
        // fprintf(saveFile, "\nPokemon Speed: %d", speed);
        // fprintf(saveFile, "\nPokemon Generation: %d", gen);
        // fprintf(saveFile, "\nPokemon legendary status: ");

        // if(legendStatus == 'F'){ // if pokemon has no genendary status
        //     fprintf(saveFile, "No\n");
        // }else{fprintf(saveFile, "Yes\n");}

        // fprintf(saveFile, "\n");
    //}
    //fclose(saveFile);


    pthread_mutex_unlock(&(data->mutex)); //locking mutex

}

int main(){

    //creating a struct with info that all threads will share and access
    SharedData data = {
        .deckSize = 0, 
        .pokeDeck = (char*)malloc(0),
        .writeFileName = (char*)malloc(0), 
        .pokeType = (char*)malloc(0),
        .flag = 0,
        .clientSocket =0};

    pthread_mutex_init(&data.mutex, NULL);//initiating mutex
    //bringing user to the menu and getting number of queries
    int totalQueries = menu(data); 

    pthread_mutex_destroy(&data.mutex);//destroying mutx

    printf("\nEnding Program.\n");//ending messages
    printf("Total number of queries: %d", totalQueries);

    return 0;
}

int menu(SharedData data){ // menu function
    //opening file and checking if the file is valid

    //initalizing variables needed to establish a server connection
    int addrSize, bytesReceived;
    struct sockaddr_in serverAddr;
    data.clientSocket = getSocket();

    // Create socket
    if(data.clientSocket == -1){
        printf("*ERROR*: Client could not open socket.\n");
        freedata(&data);
        return 1;
    }

    //creating variables to hold menu information
    
    pthread_t *threads = malloc(0);
    int numThreads = 0;
    int totalQueries = 0;

    do{
        addrSize = sizeof(serverAddr);
        
        //getting user input
        printf("\nMenu options:\n");
        printf("1. Type search\n");
        printf("2. Save results\n");
        printf("3 or other. Exit the program\n");
        printf("Enter your option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice){ //responding to user input
            case 1:
                totalQueries++;

                free(data.pokeType);

                printf("\nEnter Pokemon type: "); //getting user input type
                scanf(" %ms", &(data.pokeType));
                printf("Attempting to search for \"%s\" type\n", data.pokeType);

                //creating and starting thread
                threads = realloc(threads, ++numThreads *sizeof(pthread_t));
                pthread_create(&(threads[numThreads-1]), NULL, sendData, (void*)&data);

                break;
            case 2:

                free(data.writeFileName);
                printf("\nEnter your save file name (new file name only): "); //getting user input
                scanf(" %ms", &(data.writeFileName));
                printf("Attempting to save in \"%s\"\n", data.writeFileName);
                
                //creating and starting thread
            
                threads = realloc(threads, ++numThreads *sizeof(SharedData));
                pthread_create(&(threads[numThreads-1]), NULL, savePokemon, (void*)&data);

                break;
            default:
                data.flag = 1; // set flag to stop all threads

                send(data.clientSocket, &(data.flag), sizeof(char), 0);
                
                for(int i= 0; i<numThreads; i++){
                    pthread_join(threads[i], NULL);
                }

                //free all the struct's data
                free(threads);
                freedata(&data);
                return totalQueries;
        }
    }while(1);
    free(threads);
    freedata(&data);
    return -1;
}

void freedata(SharedData* data){
    free(data->pokeDeck);
    free(data->pokeType);
    free(data->writeFileName);
}