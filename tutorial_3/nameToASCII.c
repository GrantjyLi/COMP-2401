#include<stdio.h>
#include<string.h>

int main(){
    //initializing name string up to 25 characters
    char name[25];
    //getting user name
    printf("You can only contain English upper and lower case alphabetical letters.\n");
    printf("Enter your name, up to 25 characters: ");
    scanf("%s", name);

    //looping through the name to output letters
    for(int i=0; i< strlen(name); i++){
        printf("the #%d letter of your name is \'%c\' with an ASCII value of %d\n", i+1, name[i], name[i]);
        
    }
    return 0;
}