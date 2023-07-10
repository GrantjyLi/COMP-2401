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
    int specialDefence;
    int speed;
    char generation;
    char legendary;
} Pokemon;

void getPokemon(){
    printf("Enter the name of your chosen pokemon: ");
}

void savePokemon(){


}

void menu(FILE *fp){
    printf("\nEnter the number of the option you want:\n");
    printf("1. Type search\n");
    printf("2. Save results\n");
    printf("3. Exit the program\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        getPokemon();
        break;
    case 2:
        savePokemon();
        break;
    default:
        return;
    }
}

int main(){
    char *input;

    printf("please include file path from this directory and file prefix. i.e: \"./test.txt\"\n");
    printf("Enter destination file name: ");
    scanf("%m[^\n]", &input);

    FILE *fp = fopen(input, "r");

    while(fp == NULL){
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %ms", &input);

        if(input[0] =='n'){
            printf("Program exiting...");
            return 0;
        }

        fp = fopen(input, "r");
    }

    menu(fp);
    printf("\nEnding Program.");
    
    fclose(fp);
    free(input);

    return 0;
}