#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// length variables 
#define MAX_POKEMON_NAME_LEN 30
#define MAX_POKEMON_TYPE_LEN 10
#define MAX_POKEMON_LINE_LEN 100

typedef struct{ // struct to hold shared info by all threads
    int deckSize;
    char * pokeDeck;
    char * pokeType;
    char * writeFileName;
    pthread_mutex_t mutex;
    char flag;
    int clientSocket;
}SharedData;