#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define SERVER_PORT 6000

char *getPokemon(char * fileName, char * pokeType, char *pokeDeck);
char * getReadFile();