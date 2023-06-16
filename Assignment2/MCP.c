#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//structure for every transaction
typedef struct transaction{
    char tId[10];
    char cId[8];
    float amount;
} transaction;

void getData(transaction *list, char * input, int num){
    for(int i=0; i<num; i++){
      
    }
}

int main(){

    char template[] = "|T000000001,C0000001,0000000.00";
    int tempSize = strlen(template);

    char * input = NULL;

    printf("Enter your transactions input: ");
    scanf("%ms", &input);

    int num = strlen(input)/tempSize;

    transaction *transactionList = malloc(sizeof(transaction) * num);

    getData(transactionList, input, num);

    free(transactionList);


}
