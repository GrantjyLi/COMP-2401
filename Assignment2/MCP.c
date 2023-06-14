#include<stdio.h>

//structure for every transaction
struct transaction{
    char tId[10];
    char cId[8];
    float amount;
};

int main(){
    struct transaction t1;

    printf("enter transaction Id: ");
    scanf("%s", &t1.tId);
        
    printf("enter customer Id: ");
    scanf("%s", &t1.cId);


    printf("Transaction Id: %s\n", t1.tId);

    printf("enter transaction amount: ");
    scanf(" %f", &t1.amount);

    printf("Customer Id: %s\n", t1.cId);
    printf("Transaction amount: %0.2f\n", t1.amount);
}
