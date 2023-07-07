#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *input;

    printf("Enter file name for Pokemon information (include file prefix): ");
    scanf("%m[^\n]", &input);

    int counter =0;
    while(input[counter] != '\n'){
        printf("%c\n",input[counter]);
        counter++;
        if(counter > 10) return;
    }

    // FILE *fp = fopen("./%m", *input);

    // while (fp ==NULL){
    //     printf("file couldn't be found, please enter again or 'n' to close: ");
    //     scanf("%m[^\n]", &input);
        
    //     if(*input == 'n'){
    //         printf("Ending Program.");
    //         return(0);
    //     }
    //     fp = fopen("./%s", *input);
    // }
    // printf("%m", *input);
    // fclose(fp);
    // free(input);
}