#include<stdio.h>

//function to format output
void output(unsigned char ACD){
    //printing in character and decimal format
    //an ascii value of 'A' is the starting character representation of the ACD
    printf("Character format: %c\n", ACD + 65);
    printf("Decimal format: %u\n", ACD);

    //using a for loop and a bit mask to print the bits of the ACD character
    printf("Binary format: ");
    
    for(int i= 0; i < 8 ; i++){
        printf("%d", (ACD & (1 << (7 - i))) >> (7 - i));
    }
    
}

int main(){
	//access control descriptor string
	unsigned char ACD = 0;
    //variable for user input
	char val;

	//asking for and getting the ACD input using for loop
	printf("Enter your following permissions (y/n)\n");
	
	for(int i=0; i< 3; i++){
        printf("Permission for the #%d permission: ", (i+1));
        scanf(" %c", &val);

        //if they say 'y', ACD is incremented at the permission bit
        if (val == 'y' || val == 'Y'){
            ACD = ACD | (1 << (2 - i));
        }
    }

    //calling output function
    output(ACD);
	
	return 0;
}