#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char name[25];
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

int getPokemon(Pokemon **pokeDeck, int deckSize) {
    char *input;
    printf("\nEnter Pokemon type: ");
    scanf(" %m[^\n]", &input);

    FILE *file = fopen("pokemon.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        free(input);
        fclose(file);
        return deckSize;
    }

    Pokemon temp;
    char line[100];
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL){
        temp.type2[0] = '\0';
        sscanf(line, "%d,%25[^,],%10[^,],%10[^,],%d,%d,%d,%d,%d,%d,%d,%c,%c\n",
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
                  
        if (strcmp(temp.type1, input) == 0) {
            deckSize++;
            *pokeDeck = realloc(*pokeDeck, deckSize * sizeof(Pokemon));
            
            memcpy(&((*pokeDeck)[deckSize - 1]), &temp, sizeof(Pokemon));
        }
    }

    fclose(file);
    free(input);
    return deckSize;
}

void savePokemon(Pokemon *pokeDeck, int size){
    char *fname;
    printf("Enter your save file name: ");
    scanf(" %m[^\n]", &fname);

    FILE *saveFile = fopen(fname, "a");

    for (int i = 0; i < size; i++){
        fprintf(saveFile, "Pokemon number: %d", pokeDeck[i].number);
        fprintf(saveFile, "\nPokemon name: %s", pokeDeck[i].name);
        fprintf(saveFile, "\nPokemon type1: %s", pokeDeck[i].type1);
        fprintf(saveFile, "\nPokemon type2: %s", pokeDeck[i].type2);
        fprintf(saveFile, "\nPokemon total: %d", pokeDeck[i].total);
        fprintf(saveFile, "\nPokemon hp: %d", pokeDeck[i].hp);
        fprintf(saveFile, "\nPokemon attack: %d", pokeDeck[i].attack);
        fprintf(saveFile, "\nPokemon defence: %d", pokeDeck[i].defence);
        fprintf(saveFile, "\nPokemon Special Attack: %d", pokeDeck[i].specialAttack);
        fprintf(saveFile, "\nPokemon Special Defence: %d", pokeDeck[i].specialDefence);
        fprintf(saveFile, "\nPokemon speed: %d", pokeDeck[i].speed);
        fprintf(saveFile, "\nPokemon generation: %d", pokeDeck[i].generation);
        fprintf(saveFile, "\nPokemon legenday status: ");

        if(pokeDeck[i].specialDefence == 0){
            fprintf(saveFile, "No\n");
        }else{fprintf(saveFile, "Yes\n");}

        fprintf(saveFile, "\n");
    }
    fclose(saveFile);
    free(fname);
}

int menu(FILE *fp, Pokemon *pokeDeck){
    int deckSize = 0;

    do{
        printf("\nMenu options:\n");
        printf("1. Type search\n");
        printf("2. Save results\n");
        printf("3. Exit the program\n");
        printf("Enter your option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice){
            case 1:
                deckSize = getPokemon(&pokeDeck, deckSize);
                break;
            case 2:
                savePokemon(pokeDeck, deckSize);
                break;
            default:
                return 1;
        }
    }while(1);

    return 0;
}

int main(){
    char *input;

    printf("please include file prefix. i.e: \"test.txt\"\n");
    printf("Enter destination file name: ");
    scanf("%m[^\n]", &input);

    FILE *fp = fopen(input, "r");

    while(fp == NULL){
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %ms", &input);

        if(input[0] =='n'){
            printf("Program exiting...");
            return 0;
        }

        fp = fopen(input, "r");
    }

    Pokemon * pokeDeck = (Pokemon*)malloc(0);

    menu(fp, pokeDeck);

    printf("\nEnding Program.");
    
    fclose(fp);
    free(input);
    free(pokeDeck);

    return 0;
}