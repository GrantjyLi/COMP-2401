#include <string.h>

#include <stdlib.h>

#include <stdio.h>



char **getPokemon(char * pokeType, char **deck, char **totalSearch) { // function to search for Pokemon with wanted Type

    char line[100];

    char type[10];

    int counter =0;

    size_t totalSize =0;



    FILE *fp = fopen("Pokemon.csv", "r");

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

    }

    

    return deck;

}



int main(){

    char *pokeType;

    char **deck;

    char *typeTotal;



    for(int i = 0; i < 3; i++){

        printf("Enter type: ");

        scanf(" %m[^\n]", &pokeType);



        deck = (char**)malloc(0); 

        

        deck = getPokemon(pokeType, deck, &typeTotal);



        FILE * fname = fopen("Shit.txt", "w");

        fprintf(fname, "%s", typeTotal);

        fclose(fname);

        

        free(deck);

        free(pokeType);

    }

    

    return 0;

}