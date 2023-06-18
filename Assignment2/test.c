#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int glob;

void change(){
    glob = 3;
}

int main(){
    glob = 2;
    printf("%d\n", glob);

    change();
    printf("%d\n", glob);

    

    return 0;

}