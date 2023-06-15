#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char template[] = "|T000000001,C0000001,0000000.00";

//structure for every transaction
struct transaction{
    char tId[10];
    char cId[8];
    float amount;
};

int main(){
    char * input = NULL;
    struct transaction t1;

    printf("Enter your transactions input: ");
    scanf("%ms", &input);

    printf("%s asdawd", input);
}