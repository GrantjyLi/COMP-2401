//file find_struct.c

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "mystr.h"


#define MAX_EMPLOYEES  30
#define NAME_SIZE     16
#define NUM_NAMES 7

struct emp{
    char firstName[NAME_SIZE];
    char familyName[NAME_SIZE];
    float salary;
    float yearsWithCompany;
};


// This is a forward reference
void populateEmployee(struct emp *emp);
int cmpEmployee(struct emp *emp, char *familyName);
struct emp * findEmployee(struct emp **arr, int arraySize, char *familyName);

int main(int argc, char* argv[])
{
        struct emp empArr[MAX_EMPLOYEES];
        struct emp* empPtrArr[MAX_EMPLOYEES];

        int i;

	// initialize each element of empPtrArr to point to corresponding element of empArr.  
	
    for (i = 0; i < MAX_EMPLOYEES; i++) {
		empPtrArr[i] = &empArr[i];
	  
            
	}
	
	// populate the employee array
	for (i = 0; i < MAX_EMPLOYEES; i++) {
		// ADD CODE

        populateEmployee(empPtrArr[i]);
	  

	}
	
	// print the family name
	for (i = 0; i < MAX_EMPLOYEES; i++) printf("%s\n", empPtrArr[i]->familyName);

	// add code to search for employee against the family name "Carp"

	// if found print the record

    findEmployee(empPtrArr, MAX_EMPLOYEES, "Carp");

	// add code to search for employee against the family name "King"

	// if found print the record

    findEmployee(empPtrArr, MAX_EMPLOYEES, "King");
    

       
    return 0;
}

struct emp * findEmployee(struct emp **arr, int arraySize, char *familyName){
    for(int i = 0; i < arraySize; i++){
        
        if(cmpEmployee(arr[i], familyName) == 1){
            printf("%s %s\n", arr[i]->firstName, arr[i]->familyName);
            printf("salary = %.2f years of service = %.2f\n", arr[i]->salary, arr[i]->yearsWithCompany);
            return arr[i];
        }
    }
    return 0;
}


/**************************************************************/
/* Purpose: compare the employee record with respect to family name

Input
emp - an employee record
familyName - the key for searching an employee 

Output
None

Return
0 if the family name in the employee record does not match that of the given key
1 if the family name in the employee record matches that of the given key
*/

int cmpEmployee(struct emp *emp, char *familyName){

	// add code
	// use the -> operator to access the fields
	// recall the precedence order between "*" and "->" operators
    if(myStrCmp(emp->familyName, familyName) != 0){
        return 0;
    }
    return 1;


}


/**************************************************************/
/* populate an employee passed in by reference
 
 input/output
 emp - pointer to an emplyee to be initialized
 
 assumption:
 emp has been previously allocated
 */

void populateEmployee(struct emp *emp)
{
    int j;
 
    char *fn[NUM_NAMES] = {"John", "Jane", "David", "Dina", "Justin","Jennifer", "Don"};
    char *sn[NUM_NAMES] = {"Smith", "Johnson", "Mart", "Carp", "Farmer","Ouster","Door"};


    // get a random value and make sure that it is in the range of 0-30000
    emp->salary = rand() % 30000;
    emp->yearsWithCompany = rand() % 30;
    j = rand() % NUM_NAMES;
    strncpy(emp->firstName, fn[j],NAME_SIZE-1);
    j = rand() % NUM_NAMES;
    strncpy(emp->familyName, sn[j],sizeof(emp->familyName)-1);

}
