#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// length variables 
#define MAX_POKEMON_NAME_LEN 30
#define MAX_POKEMON_TYPE_LEN 10
#define MAX_POKEMON_LINE_LEN 100

typedef struct{ //pokemon struct
    int number;
    char name[MAX_POKEMON_NAME_LEN];
    char type1[MAX_POKEMON_TYPE_LEN];
    char type2[MAX_POKEMON_TYPE_LEN];
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

typedef struct{ // struct to hold shared info by all threads
    int deckSize;
    Pokemon *pokeDeck;
    char * pokeType;
    char * readFileName;
    char * writeFileName;
    pthread_mutex_t mutex;
    char flag;
} SharedData;

void *getPokemon(void *dataIn);
void *savePokemon(void *dataIn);