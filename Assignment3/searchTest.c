#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char name[15];
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

void getPokemon(Pokemon *pokeDeck, int deckSize){
    char *input;
    printf("Enter the name of your chosen pokemon: ");
    scanf("%m[^\n]", &input);

    int read;
    int pokeNum;
    char pokeName[15];
    FILE *file = fopen("pokemon.csv", 'r'); 

    while(!feof(file)){
        read = fscanf(file, "%d,%15[^,]", &pokeNum, &pokeName);
        printf("%d\n", pokeNum);
        if(strcmp(pokeName, input)){
            realloc(pokeDeck, deckSize * sizeof(Pokemon));
            printf("Pokemon found\n");

            char type1[10];
            read = fscanf(file, "%d,", &type1);
            printf("type is: %s\n", type1);
        }
        
    }

    fclose(file);
    free(input);
}

int main(){
    Pokemon *pokeDeck = (Pokemon*)malloc(sizeof(Pokemon));

    getPokemon(pokeDeck, 1);

    for(int i=0; i<1; i++){
        printf("%s + ", pokeDeck[0].name);
        printf("%d\n", pokeDeck[0].speed);
    }

    free(pokeDeck);
}