#include<stdio.h>
int main(){
	//access control descriptor string
	char ACD[3];

	//asking for and getting the ACD input
	printf("Enter your 3 character long permission descriptor: ");
	scanf("%s", ACD);
	
	//calling output function
	output(ACD);
	return 0;
}

//output function for output format
void output(char ACD[3]){
	printf("Your permissions are:\n");
	printf("character format: %s", ACD);
	printf("character format: %d", ACD);
}
