#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 6000

int getPokemon(char * readFile, char * pokeType, char **deck, char **totalSearch);
char * getReadFile();