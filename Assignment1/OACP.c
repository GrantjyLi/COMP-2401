#include<stdio.h>
#include<math.h>

//output function for output format
void output(char (*ACD)[3]){
	//integer to track decimal for output
	int d=0;

	//integer to track number of elements in the array
	int s =(sizeof((*ACD)) / sizeof((*ACD)[0]));

	printf("Your permissions are:\n");
	printf("character format: %s\n", (*ACD));
	printf("binary format: ");

	//looping through the character array to print binary if each permission is yes or not
	for(int i=0; i< s; i++){
		
		if ((*ACD)[i] == 'Y' || (*ACD)[i] == 'y'){
			printf("1");
			d += pow(2, s-i-1);
		}else {
			printf("0");
		}
	
	}
	printf("\nDecimal format: %d", d);
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