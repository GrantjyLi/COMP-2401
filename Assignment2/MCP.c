#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct transaction{//structure for every transaction
    char tId[11];
    char cId[9];
    float amount;
} transaction;

//getData method returns a pointer to a transaction list
void getData(int tempSize){
    //char pointer to get input from user and int for number of transactions
    char * input;

    //getting the transaction input
    printf("Enter your transactions input: ");
    scanf("%m[^\n]", &input);

    if(input == NULL){ //checking for invalid input
        printf("No input given, program ending");
        free(input);
        return 0;
    }

    //mallocing memory for the transaction struct array with the size of the number of transactions
    transaction * transactionList = malloc(sizeof(transaction) * (strlen(input)/tempSize));

    //variables used to copy parts of the transaction input into a struct
    int infoIndex=0;
    char status;
    char info[11];
    int numTransactions = 0;

    //looping through the input string one letter at a tme
    for(int i=0; i< strlen(input); i++){

        //if the current character is a '|', action is taken to process a new transaction
        if(input[i] == '|'){
            
            if(i > 0){ //entering the amount for the previous transaction
                transactionList[numTransactions-1].amount = atof(info);
            }

            status = 'T';//status is changed to take in transaction ID
            //incrementing number of transactions
            //reseting the variable that tracks the current thing being indexed through (customerID, transactionID, or Amount)
            numTransactions++;
            infoIndex = 0;

            continue;
        }else if(input[i] == ',' && status == 'T'){//just finished scanning a transaction ID 
            info[10] = '\0'; //putting the escape character at the end of a string
            strcpy(transactionList[numTransactions-1].tId, info);//entering transaction ID
            
            status = 'C'; //indexing a customer ID now 
            infoIndex=0;
            continue;
        }else if(input[i] == ',' && status == 'C'){//just finished scanning a Customer ID
            
            info[8] = '\0';
            strcpy(transactionList[numTransactions-1].cId, info);//entering customer ID

            status = 'A'; //indexing amount now
            infoIndex=0;
            continue;
        }

        //taking information into the info string using the input and an index
        info[infoIndex] = input[i];
        infoIndex++;
        
    }
    
    if(status != 0){// getting the last transaction's amount
        transactionList[numTransactions-1].amount = atof(info);
    }

    //printing data and freeing the transaction list memory
    printData(transactionList, numTransactions);
    //freeing the input space and returning the array pointer
    free(input);
    free(transactionList);
}

//method to print the tranaction
void printData(transaction * transactionList, int numTransactions){
    float total = 0; //to track the total transaction list amount

    //looping for the number of transactions and printing each one using a format
    for(int i=0; i < numTransactions; i++){
        printf("---------------------------------\n");
        printf("Transaction Id: %s\n", transactionList[i].tId);
        printf("Customer Id: %s\n", transactionList[i].cId);
        printf("Transaction amount: $%.2f\n", transactionList[i].amount);
        total += transactionList[i].amount;
    }

    //printing average and total transaction information
    printf("**********************************\n");
    printf("Average transaction amount is: $%.2f\n", total/numTransactions);
    printf("Total transaction number is: %d\n", numTransactions);
    printf("**********************************\n");
}

int main(){
    //template input for reference
    char template[] = "|T123456789,C1234567,1234567.89";

    //getData handles the rest of the input and calls output
    getData(strlen(template));
    
    return 0;
}