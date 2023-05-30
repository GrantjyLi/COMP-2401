#include<stdio.h>

void output(unsigned char c){
    printf("Character format: %c\n", c + 32);
    printf("Decimal format: %u\n", c);
    printf("Binary format: ");
    
    for(int i= 0; i < 3 ; i++){
        printf("%d", (c & (1 << (2 - i))) >> (2 - i));
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