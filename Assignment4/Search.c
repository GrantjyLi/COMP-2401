#include "Search.h"

int getPokemon(char * readFile, char * pokeType, char **deck, char **totalSearch) { // function to search for Pokemon with wanted Type
    char line[100];
    char type[10];
    int counter =0;
    size_t totalSize =0;

    FILE *fp = fopen(readFile, "r");
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL){
        
        sscanf(line, " %*d,%*[^,],%[^,],\n", type);
        
        if (strcmp(pokeType, type) == 0){

            deck = realloc(deck, (counter+1) * sizeof(char*));
            deck[counter] = malloc(strlen(line) +1);
            strcpy(deck[counter], line);
            deck[counter][strlen(line)] = '\0';

            totalSize += strlen(line) +1;
            
            counter++;
        }
    }
    fclose(fp);

    *totalSearch = malloc(totalSize * sizeof(char));
    for (int i = 0; i < counter; i++){
        strcat(*totalSearch, deck[i]);
        free(deck[i]);
    }
    free(deck);

    return counter;
}