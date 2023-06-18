#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int numTransactions =0;

//structure for every transaction
typedef struct transaction{
    char tId[11];
    char cId[9];
    float amount;
} transaction;

//getData method returns a pointer to 
transaction * getData(int tempSize){
    char * input = NULL;

    printf("Enter your transactions input: ");
    scanf("%ms", &input);
    
    transaction *transactionList = malloc(sizeof(transaction) * (strlen(input)/tempSize));
    
    int infoIndex=0;
    char status;
    char info[11];

    numTransactions =-1;

    for(int i=0; i< strlen(input); i++){

        if(input[i] == '|'){
            status = 'T';

            if(i > 0){  
                transactionList[numTransactions].amount = atof(info);
            }

            numTransactions++;
            
            infoIndex=0;

            continue;
        }else if(input[i] == ',' && status == 'T'){
            status = 'C';
            infoIndex=0;
            

            info[10] = '\0';
            strcpy(transactionList[numTransactions].tId, info);

            continue;
        }else if(input[i] == ',' && status == 'C'){
            status = 'A';
            infoIndex=0;

            info[8] = '\0';
            strcpy(transactionList[numTransactions].cId, info);

            continue;
        }

        info[infoIndex] = input[i];
        infoIndex++;
        
    }
    
    if(status != 0){
        transactionList[numTransactions].amount = atof(info);
    }

    free(input);
    return transactionList;
}

void printData(transaction * transactionList){
    for(int i=0; i <= numTransactions; i++){
        printf("Transaction Id: %s\n", transactionList[i].tId);
        printf("Customer Id: %s\n", transactionList[i].cId);
        printf("Transaction amount: $%.2f\n", transactionList[i].amount);
    }
}

int main(){
    //template input and size for reference
    char template[] = "|T000000001,C0000001,0000000.00";
    int tempSize = strlen(template);

    transaction * transactionList = getData(tempSize);

    printData(transactionList);

    free(transactionList);
    return 0;
}
