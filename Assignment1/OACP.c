#include<stdio.h>

//output function for output format
void output(char ACD){
	printf("%c", ACD);
}

int main(){
	//access control descriptor string
	char ACD = 0;
	char val = 'd';
	int d =0;
	//asking for and getting the ACD input
	printf("Enter your following permissions (y/n)\n");
	
	printf("Permission to read (1st): ");
	scanf(" %c", &val);

	if (val == 'y' || val == 'Y'){
		ACD++;
		ACD << 2;
	}

	printf("Permission to write (2nd): ");
	scanf(" %c", &val);

	if (val == 'y' || val == 'Y'){
		ACD++;
		ACD << 1;
	}

	printf("Permission to execute (3rd): ");
	scanf(" %c", &val);

	if (val == 'y' || val == 'Y'){
		ACD++;
	}
	
	//calling output function
	//output(ACD);

	printf("%c lol", ACD);

	printf("\n%d", ACD);

	return 0;
}