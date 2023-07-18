#include <stdio.h>
void fprint()
{
    FILE *fid = fopen("workers", "r");
    // add code
    char name[30];
    char lname[30];
    char age;
	// while not end of file
    while(!feof(fid)){
        fscanf(fid, "%30c%30c%d\n", name, lname, &age);
        printf("%s%s%d\n", name, lname, age);

    }
	// read a values in a line

	// print the values to the screen 
    fclose(fid);
}
int main(){
    fprint();
    return 0;
}

