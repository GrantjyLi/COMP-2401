#include<stdio.h>

//output function for output format
void output(char (*ACD)[3]){
	//integer to track decimal for output
	int d=0;

	printf("Your permissions are:\n");
	printf("character format: %s\n", (*ACD));
	printf("binary format: ");

	for(int i=0; i< (sizeof((*ACD)) / sizeof((*ACD)[0])); i++){
		//printf("%c", (*ACD)[i]);
		
		if ((*ACD)[i] == 'Y' || (*ACD)[i] == 'y'){
			printf("1");
		}else {
			printf("0");
		}
	
	}
}

int main(){
	//access control descriptor string
	char ACD[3];

	//asking for and getting the ACD input
	printf("Enter your 3 character long permission descriptor: ");
	scanf("%s", ACD);
	
	//calling output function
	output(&ACD);
	return 0;
}