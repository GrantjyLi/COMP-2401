#include "FileIO.h"

int menu(SharedData data){ // menu funcction

    //opening file and checking if the file is valid
    FILE * fp = fopen(data.readFileName, "r");
    while(fp == NULL){ // if not a valid file, loop until valid file or exit
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %m[^\n]", &(data.readFileName));

        if(data.readFileName[0] =='n'){ //exiting after freeing data 
            printf("Program exiting...");
                free(data.pokeDeck);
                free(data.pokeType);
                free(data.readFileName);
                free(data.writeFileName);
            return 0;
        }
        fp = fopen(data.readFileName, "r");
    }
    fclose(fp);

    //creating variables to hold menu information
    pthread_t *threads = malloc(0);
    int numThreads = 0;
    int totalQueries = 0;

    do{ //getting user input
        printf("\nMenu options:\n");
        printf("1. Type search\n");
        printf("2. Save results\n");
        printf("3. Exit the program\n");
        printf("Enter your option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice){ //responding to user input
            case 1:
                totalQueries++;

                printf("\nEnter Pokemon type: "); //getting user input type
                scanf(" %m[^\n]", &(data.pokeType));
                printf("Attempting to search for \"%s\" type\n", data.pokeType);

                //creating and starting thread
                threads = realloc(threads, ++numThreads *sizeof(SharedData));
                pthread_create(&(threads[numThreads-1]), NULL, getPokemon, (void*)&data);
                
                break;
            case 2:
                printf("\nEnter your save file name (new file name only): "); //getting user input
                scanf(" %m[^\n]", &(data.writeFileName));
                printf("Attempting to save in \"%s\"\n", data.writeFileName);
                
                //creating and starting thread
                threads = realloc(threads, ++numThreads *sizeof(SharedData));
                pthread_create(&(threads[numThreads-1]), NULL, savePokemon, (void*)&data);

                break;
            default:
                data.flag = 1; // set flag to stop all threads

                for(int i= 0; i<numThreads; i++){
                    pthread_detach(threads[i]);
                }
                //free all the struct's data
                free(threads);
                free(data.pokeDeck);
                free(data.pokeType);
                free(data.readFileName);
                free(data.writeFileName);
                return totalQueries;
        }
    }while(1);
    free(threads);
    return totalQueries;
}

int main(){
    //creating a struct with info that all threads will share and access
    SharedData data = {
            .deckSize = 0, 
            .pokeDeck = (Pokemon*)malloc(0), 
            .readFileName = NULL, 
            .writeFileName = NULL, 
            .pokeType = NULL,
            .flag = 0};

    //getting user input
    printf("Input is case sensitive and include file suffix. i.e: \"Test.txt\"\n");
    printf("Enter destination file name: ");
    scanf("%m[^\n]", &(data.readFileName));

    pthread_mutex_init(&data.mutex, NULL);//initiating mutex
    //bringing user to the menu and getting number of queries
    int totalQueries = menu(data); 

    pthread_mutex_destroy(&data.mutex);//destroying mutx

    printf("\nEnding Program.\n");//ending messages
    printf("Total number of queries: %d", totalQueries);

    return 0;
}