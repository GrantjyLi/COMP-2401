#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[5];
    printf("enter: ");
    scanf("%s", &arr);

    int i=0;
    while(arr[i] != '\n'){
        printf("%c\n", arr[i]);
        i++;
    }
    

    return 0;

}