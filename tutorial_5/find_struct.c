//file find_struct.c

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define MAX_EMPLOYEES  30
#define NAME_SIZE     16
#define NUM_NAMES 7

struct emp{
    char firstName[NAME_SIZE];
    char familyName[NAME_SIZE];
    float salary;
    float yearsWithCompany;
};

// forward declaration

void populateEmployee(struct emp *emp);
int cmpEmployee(struct emp *emp, char *familyName);

int cmpEmployee(struct emp *p, char *familyName){
	
	return !strcmp(p->familyName, familyName);
}

struct emp * findEmployee(struct emp **arr, int arraySize, char*familyName){

	for (int i = 0; i < arraySize; i++){
//		printf("%s, %s", *arr[i]->firstName, *arr[i]->familyName);
		if(cmpEmployee(arr[i], familyName) == 1){
			return arr[i];
		}
	}
	return NULL;
	
}

int main(int argc, char* argv[])
{
    
    struct emp **empArr = NULL;

    int i;
    int rc;

	// Allocate memory for the array empArr (which is an array of pointers)
	
	empArr = (struct emp **) malloc(sizeof(struct emp *) * MAX_EMPLOYEES);
	// check if allocation was successful 
	if (empArr == NULL) {
		printf("error: could not allocate memory for the array \n");
		return(1);
	}

	// initialize each of the elements to NULL.  
	// ADD CODE

	for(i =0; i< MAX_EMPLOYEES; i++){
		empArr[i] = NULL;
	}


	// create an employee element by allocating new memory 
	// for each employee using malloc() and populate that element
	for (i = 0; i < MAX_EMPLOYEES; i++) {
		empArr[i] = (struct emp *)malloc(sizeof(struct emp));
		if(empArr[i] == NULL){
			printf("Couldn't initialize employees in memory.\n");
			return 1;
		}
		
		populateEmployee(empArr[i]);
	}


	// print the family name
	for (i = 0; i < MAX_EMPLOYEES; i++) printf("%s\n", empArr[i]->familyName);

	// add code to search for employee against the family name "Carp"

	// if found print the record

	struct emp * employee;

	employee = findEmployee(empArr, MAX_EMPLOYEES, "Carp");
	if(employee != NULL){
		printf("%s %s\n",employee->firstName, employee->familyName);
		printf("salary= %.2f years of service = %.2f", employee->salary, employee->yearsWithCompany);
			
	}
	
	// add code to search for employee against the family name "King"

	// if found print the record

	employee = findEmployee(empArr, MAX_EMPLOYEES, "King");
	if(employee != NULL){
		printf("%s %s\n",employee->firstName, employee->familyName);
		printf("salary= %.2f years of service = %.2f", employee->salary, employee->yearsWithCompany);
	}

	for (i = 0; i < MAX_EMPLOYEES; i++) free(empArr[i]);
	free(empArr);
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

/**************************************************************/
/* populate an employee passed in by reference
 
 input/output
 emp - pointer to an emplyee to be initialized
 
 assumption:
 emp exists
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