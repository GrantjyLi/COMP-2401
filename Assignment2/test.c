#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct transaction{
    char tId[10];
    float amount;
} transaction;

int main(){
    int length =2;
    transaction * array = malloc(sizeof(transaction) * length);


    strcpy(array[0].tId, "T000000001");
    array[0].amount = 123.34;

    for (int i = 0; i < length; i++){
        printf("enter transaction id: ");
        scanf("%s", &array[i].tId);
        printf("enter transaction amount: ");
        scanf("%f", &array[i].amount);
    }

    for(int i = 0; i < length; i++){
        printf("\n_______________________________");
        printf("\ntransaction ID: %s", array[i].tId);
        printf("\ntransaction amount: %0.2f", array[i].amount);
    }
    
    free(array);

    return 0;

}