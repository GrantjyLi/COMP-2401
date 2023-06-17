#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//structure for every transaction
typedef struct transaction{
    char tId[10];
    char cId[8];
    float amount;
} transaction;

transaction * getData(int tempSize){
    char * input = NULL;

    printf("Enter your transactions input: ");
    scanf("%ms", &input);
    
    transaction *transactionList = malloc(sizeof(transaction) * (strlen(input)/tempSize));
    printf("%d\n", sizeof(*transactionList));
    
    int currTransaction = -1, infoCounter=0;
    char status;
    char info[10];
    for(int i=0; i< strlen(input); i++){
        if(input[i] == '|'){
            status = 'T';
            currTransaction++;
            
            infoCounter=0;

            if(i > 0){
                transactionList[currTransaction].amount = atof(info);
            }
            
            continue;
        }else if(input[i] == ',' && status == 'T'){
            status = 'C';
            infoCounter=0;

            strcpy(transactionList[currTransaction].tId, info);

            continue;
        }else if(input[i] == ',' && status == 'C'){
            status = 'A';
            infoCounter=0;

            strcpy(transactionList[currTransaction].cId, info);

            continue;
        }

        info[infoCounter] = input[i];
        
    }
    
    if(status != 0){
        transactionList[currTransaction].amount = atof(info);
    }
    printf("%d %d", sizeof(*transactionList), sizeof(transaction) * (strlen(input)/tempSize));
    return transactionList;
}

void printData(transaction * transactionList){
    for(int i=0; i< sizeof(transactionList)/sizeof(transaction); i++){
        printf("Transaction Id: %s\n", transactionList[i].tId);
        printf("Customer Id: %s\n", transactionList[i].cId);
        printf("Transaction amount: %.2f\n", transactionList[i].amount);
    }
}

int main(){
    //template input and size for reference
    char template[] = "|T000000001,C0000001,0000000.00";
    int tempSize = strlen(template);

    transaction * transactionList = getData(tempSize);

    printData(transactionList);

    for(int i=0; i< sizeof(transactionList)/sizeof(transaction); i++){
        free(&transactionList[i]);
    }

    free(transactionList);
    return 0;
}
