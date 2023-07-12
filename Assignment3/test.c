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

void save(Pokemon *pokeDeck){
    printf("%d", pokeDeck[0].number);
}

int main(){
    Pokemon *pokeDeck = malloc(sizeof(Pokemon));

    Pokemon bulbasaur;
    bulbasaur.number = 1;
    bulbasaur.name = "bulbasaur";
    bulbasaur.type1 = "Grass";
    bulbasaur.type2 = "Poison";
    bulbasaur.hp = 318;
    bulbasaur.attack = 45;
    bulbasaur.defence = 49;
    bulbasaur.specialAttack = 49;
    bulbasaur.specialDefence = 65;
    bulbasaur.speed = 65;
    bulbasaur.generation = 1;
    bulbasaur.legendary = 0;

    pokeDeck[0] = bulbasaur;

    save(pokeDeck);
    free(pokeDeck);
}