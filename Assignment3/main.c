#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct{
    int number;
    char name[30];
    char type1[10];
    char type2[10];
    int total;
    int hp;
    int attack;
    int defence;
    int specialAttack;
    int specialDefence;
    int speed;
    char generation;
    char legendary;
} Pokemon;

typedef struct{
    int deckSize;
    Pokemon *pokeDeck;
    char * pokeType;
    char * readFileName;
    char * writeFileName;
    char flag;
    pthread_mutex_t mutex;
} SharedData;

void *getPokemon(void *dataIn) {
    SharedData *data = (SharedData*)dataIn;

    Pokemon temp;

    FILE *fp = fopen(data->readFileName, "r");

    char line[100];
    fgets(line, sizeof(line), fp);
    while (fgets(line, sizeof(line), fp) != NULL){
        
        temp.type2[0] = '\0';
        sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%c,%c\n",
                  &temp.number,
                  temp.name,
                  temp.type1,
                  temp.type2,
                  &temp.total,
                  &temp.hp,
                  &temp.attack,
                  &temp.defence,
                  &temp.specialAttack,
                  &temp.specialDefence,
                  &temp.speed,
                  &temp.generation,
                  &temp.legendary);

        if (strcmp(temp.type1, data->pokeType) == 0) {
            pthread_mutex_lock(&(data->mutex));
            
            data->deckSize++;
            data->pokeDeck = realloc(data->pokeDeck, data->deckSize * sizeof(Pokemon));
            memcpy(&(data->pokeDeck[data->deckSize-1]), &temp, sizeof(Pokemon));
            
            pthread_mutex_unlock(&(data->mutex));
        }
    }
    fclose(fp);
}

void *savePokemon(void *dataIn){
    SharedData *data = (SharedData*)dataIn;
    FILE *saveFile = fopen(data->writeFileName, "w");

    for (int i = 0; i < data->deckSize; i++){
        fprintf(saveFile, "Pokemon: #%d - %s", data->pokeDeck[i].number, data->pokeDeck[i].name);
        fprintf(saveFile, "\nPokemon Types: %s - %s", data->pokeDeck[i].type1, data->pokeDeck[i].type2);
        fprintf(saveFile, "\nPokemon Total: %d", data->pokeDeck[i].total);
        fprintf(saveFile, "\nPokemon HP: %d", data->pokeDeck[i].hp);
        fprintf(saveFile, "\nPokemon Attack & Defence: %d - %d", data->pokeDeck[i].attack, data->pokeDeck[i].defence);
        fprintf(saveFile, "\nPokemon Special Attack & Defence: %d - %d", data->pokeDeck[i].specialAttack,  data->pokeDeck[i].specialDefence);
        fprintf(saveFile, "\nPokemon Speed: %d", data->pokeDeck[i].speed);
        fprintf(saveFile, "\nPokemon Generation: %d", data->pokeDeck[i].generation);
        fprintf(saveFile, "\nPokemon legendary status: ");

        if(data->pokeDeck[i].specialDefence == 0){
            fprintf(saveFile, "No\n");
        }else{fprintf(saveFile, "Yes\n");}

        fprintf(saveFile, "\n");
    }
    printf("saved");
    fclose(saveFile);
}

void menu(SharedData data){
    int deckSize = 0;
    pthread_t *threads = malloc(0);
    int numThreads =0;

    FILE * fp = fopen(data.readFileName, "r");
    while(fp == NULL){//possible memory leak with file
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %ms", &(data.readFileName));

        if((data.readFileName)[0] =='n'){
            printf("Program exiting...");
        }
        fp = fopen(data.readFileName, "r");
    }
    fclose(fp);

    do{
        printf("\nMenu options:\n");
        printf("1. Type search\n");
        printf("2. Save results\n");
        printf("3. Exit the program\n");
        printf("Enter your option: ");

        int choice;
        scanf(" %d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter Pokemon type: ");
                scanf(" %m[^\n]", &(data.pokeType));

                threads = realloc(threads, ++numThreads *sizeof(SharedData));
                pthread_create(&(threads[numThreads-1]), NULL, getPokemon, (void*)&data);
                
                break;
            case 2:
                printf("\nEnter your save file name (new file name only): ");
                scanf(" %m[^\n]", &(data.writeFileName));

                threads = realloc(threads, ++numThreads *sizeof(SharedData));
                pthread_create(&(threads[numThreads-1]), NULL, savePokemon, (void*)&data);

                break;
            default:
                free(threads);
                return;
        }
    }while(1);
    free(threads);
}

int main(){
    Pokemon * pokeDeck = (Pokemon*)malloc(0);
    SharedData data = {
            .deckSize = 0, 
            .pokeDeck = pokeDeck, 
            .readFileName = NULL, 
            .writeFileName = NULL, 
            .pokeType = NULL, 
            .flag = 0};

    printf("Include file prefix. i.e: \"test.txt\"\n");
    printf("Enter destination file name: ");
    scanf("%m[^\n]", &(data.readFileName));

    pthread_mutex_init(&data.mutex, NULL);
    
    menu(data);

    printf("\nEnding Program.");

    free(pokeDeck);
    free(data.pokeType);
    free(data.readFileName);
    free(data.writeFileName);

    return 0;
}