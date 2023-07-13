#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char *name;
    char *type1;
    char *type2;
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

void getPokemon(Pokemon *pokeDeck, int deckSize){
    char *input;
    printf("Enter the name of your chosen pokemon: ");
    scanf("%m[^\n]", &input);

    //if found:
    realloc(pokeDeck, deckSize * sizeof(Pokemon));


    free(input);
}

void savePokemon(Pokemon *pokeDeck){
    printf("chesses\n");

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
                deckSize++;
                getPokemon(pokeDeck, deckSize);
                break;
            case 2:
                savePokemon(pokeDeck);
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