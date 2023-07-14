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
    FILE *file = fopen("pokemon.csv", "r"); 
    
    Pokemon temp; 
    fscanf(file, "%*[^\n]\n");
    while(!feof(file)){
        read = fscanf(file, "%d,%15[^,],%10[^,],%10[^,],%d,%d,%d,%d,%d,%d,%d,%c,%c%*c", 
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
                
        if(strcmp(temp.type1, input) ==0){
            realloc(pokeDeck, deckSize * sizeof(Pokemon));
            pokeDeck[deckSize-1] = temp;
            deckSize++;
            printf("%s\n", temp.name);
            printf("%d ", temp.number);
            printf("%d ", temp.speed);
            break;
        }
        fscanf(file, "%*[^\n]\n");
       
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