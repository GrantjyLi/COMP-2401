#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int getPokemon(Pokemon **pokeDeck, int deckSize) {
    char *input;
    printf("Enter the name of your chosen pokemon: ");
    scanf(" %m[^\n]%*c", &input);

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


int main(){
    Pokemon *pokeDeck = (Pokemon*)malloc(0);

    int decksize = getPokemon(&pokeDeck, 0);
    for(int i=0; i<decksize; i++){
        printf("%s, %s, %s\n", pokeDeck[i].name, pokeDeck[i].type1, pokeDeck[i].type2);
    }
    printf("%d", decksize);

    free(pokeDeck);
}