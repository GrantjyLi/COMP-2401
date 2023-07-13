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

void save(Pokemon *pokeDeck, FILE *saveFile, int size){

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

}

int main(){
    Pokemon *pokeDeck = malloc(2 * sizeof(Pokemon));

    Pokemon bulbasaur;
    bulbasaur.number = 1;
    bulbasaur.name = "bulbasaur";
    bulbasaur.type1 = "Grass";
    bulbasaur.type2 = "Poison";
    bulbasaur.total = 318;
    bulbasaur.hp = 45;
    bulbasaur.attack = 49;
    bulbasaur.defence = 49;
    bulbasaur.specialAttack = 65;
    bulbasaur.specialDefence = 65;
    bulbasaur.speed = 45;
    bulbasaur.generation = 1;
    bulbasaur.legendary = 0;

    Pokemon charmander;
    charmander.number = 4;
    charmander.name = "charmander";
    charmander.type1 = "Fire";
    charmander.type2 = "";
    charmander.total= 309;
    charmander.hp = 39;
    charmander.attack = 52;
    charmander.defence = 43;
    charmander.specialAttack = 60;
    charmander.specialDefence = 50;
    charmander.speed = 65;
    charmander.generation = 1;
    charmander.legendary = 0;

    //4,Charmander,Fire,,309,39,52,43,60,50,65,1,False

    pokeDeck[0] = bulbasaur;
    pokeDeck[1] = charmander;

    FILE *saveFile = fopen("Pokedeck.txt", "w");

    save(pokeDeck, saveFile, 2);
    free(pokeDeck);
    fclose(saveFile);
}