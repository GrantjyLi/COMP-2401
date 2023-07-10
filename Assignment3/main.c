#include <stdio.h>
#include <stdlib.h>

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

void menu(FILE *fp){
    printf("Enter the number of the option you want:\n");
    printf("1. Type search\n");
    printf("2. Save results\n");
    printf("3. Exit the program\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 2:

        break;
    default:
        return;
    }

}

int main(){
    // char *input;

    // printf("Enter file name for Pokemon information (include file prefix): ");
    // scanf("%m[^\n]", &input);

    char input[] = "./pokemon.csv";
    
    FILE *fp = fopen(input, "r");

    while(fp == NULL){
        printf("File not found, enter 'n' to exit or file name again: ");
        scanf(" %s", &input);

        if(input[0] =='n'){
            printf("Program exiting...");
            return 0;
        }

        fp = fopen(input, "r");
    }

    menu(fp);

    fclose(fp);
    //free(input);
}