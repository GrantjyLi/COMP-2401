#include "FileIO.h"

void *getPokemon(void *dataIn) { // function to search for Pokemon with wanted Type
    //creating data pointer variable to access attributes
    SharedData *data = (SharedData*)dataIn;

    Pokemon temp; //temporary pokemon struct to scan data into

    //opening file and reading through all the lines with pokemon data
    FILE *fp = fopen(data->readFileName, "r");

    char line[MAX_POKEMON_LINE_LEN];
    fgets(line, sizeof(line), fp);
    while (fgets(line, sizeof(line), fp) != NULL){

        if(data->flag == 1) return NULL; // closing thread
        
        temp.type2[0] = '\0'; // avoiding using last type2 if current one doesn't exit
        //scanning all the data into the temporary pokemon struct
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

        //if the temporary pokemon has the wanted type
        if (strcmp(temp.type1, data->pokeType) == 0){
            pthread_mutex_lock(&(data->mutex)); //unlock mutex
            
            //add temporary pokemon data to the total list of pokemon indexed
            data->deckSize++;
            data->pokeDeck = realloc(data->pokeDeck, data->deckSize * sizeof(Pokemon));
            memcpy(&(data->pokeDeck[data->deckSize-1]), &temp, sizeof(Pokemon));
            
            pthread_mutex_unlock(&(data->mutex));//lock mutex
        }
    }
    fclose(fp);

}

void *savePokemon(void *dataIn){ // function to write a file with all indexed pokemon's data
    //creating data pointer variable to access attributes
    SharedData *data = (SharedData*)dataIn;

    //creating and looping through new user file
    FILE *saveFile = fopen(data->writeFileName, "w");
    for (int i = 0; i < data->deckSize; i++){

        if(data->flag == 1) return NULL; // closing thread

        //writing each pokemon indexed in a format
        fprintf(saveFile, "Pokemon: #%d - %s", data->pokeDeck[i].number, data->pokeDeck[i].name);
        fprintf(saveFile, "\nPokemon Types: %s - %s", data->pokeDeck[i].type1, data->pokeDeck[i].type2);
        fprintf(saveFile, "\nPokemon Total: %d", data->pokeDeck[i].total);
        fprintf(saveFile, "\nPokemon HP: %d", data->pokeDeck[i].hp);
        fprintf(saveFile, "\nPokemon Attack & Defence: %d - %d", data->pokeDeck[i].attack, data->pokeDeck[i].defence);
        fprintf(saveFile, "\nPokemon Special Attack & Defence: %d - %d", data->pokeDeck[i].specialAttack,  data->pokeDeck[i].specialDefence);
        fprintf(saveFile, "\nPokemon Speed: %d", data->pokeDeck[i].speed);
        fprintf(saveFile, "\nPokemon Generation: %d", data->pokeDeck[i].generation);
        fprintf(saveFile, "\nPokemon legendary status: ");

        if(data->pokeDeck[i].specialDefence == 0){ // if pokemon has no type2
            fprintf(saveFile, "No\n");
        }else{fprintf(saveFile, "Yes\n");}

        fprintf(saveFile, "\n");
    }
    fclose(saveFile);

}