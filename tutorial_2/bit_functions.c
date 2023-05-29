
/* file is bit_functions.c 
Purpose: helper functions for bit manipulation

*/

#include "bit_functions.h"

/*
Purpose: checks if bit in position bitNum of the character c is set to 1 
input:
c - a character
bitNum - the bit position

return
1 if the bits is set
0 is the bit is not set

*/
int isBitSet(unsigned char c, int bitNum) 
{

    return (c & (1 << bitNum)) >> bitNum;
	
}


/***************************************************************/


/*
Purpose: sets bit in position bitNum of the character c to 1 
input:
c - a character 
bitNum - the bit position

return
the modified character

*/
unsigned char setBit(unsigned char c, int bitNum) 
{
    return (1 << bitNum) | c;
	
}


/***************************************************************/

/*
Purpose: clears bit in position bitNum of the character c 
input:
c - a character upon
bitNum - the bit position

return
the modified character

*/

unsigned char clearBit(unsigned char c, int bitNum) 
{

    return ~(~c | (1 << bitNum));
}

/***************************************************************/

/*
Purpose: prints the bits of the the character using an iterative method 
input:
c - a character that its bits must be printed

return
none

*/

void printBitsIterative(unsigned char c) 
{
  
    for(int i= 7; i >= 0 ; i--){
        printf("%d", isBitSet(c, i));
           
    }
    printf("\n");
}

/***************************************************************/


/*
Purpose: prints the bits of the the character using recurive method
input:
c - a character that its bits must be printed

return
none

*/

void printBitsRecursive(unsigned char c) 
{

}