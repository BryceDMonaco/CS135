#include <stdio.h>

	//Initialize and assign values that allow the while loop to run at least once
	//Woo globals
	int colAmount = -1, rowAmount = -1;

int main (void) {
	
	
	
	printf("This program counts occurrences of digits 0 through 9 in an NxM array");
	printf("Enter the size of your array (\"N M\"): ");
	
	//Keep waiting for values that fufill the conditions
	while (!(colAmount >= 0) && !(rowAmount >= 0)) {
		scanf("%d %d", &colAmount, &rowAmount);
		
		if ((colAmount >= 0) && (rowAmount >= 0)) {
			printf("Making an array with %d rows and %d columns.\n", rowAmount, colAmount);
		
		} else {
			printf("Invalid array size. Ensure both values are >= 0 and are integers.\n");
			printf("Enter the size of your array (\"N M\"): ");
			
		}
	}
	
	//Create the array and fill it with zeroes
	int digitArray[rowAmount][colAmount] = {0};
	
	//Fill the array with placeholder values
	for (int i = 0; i < (rowAmount - 1); i++) {
		for (int ii = 0; ii < (colAmount - 1); ii++) {
			digitArray[i][ii] = 9999; //9999 is a placeholder
		
		}
	}
	
	//Loop to call read_row
		//
	for (int i = 0; i < (rowAmount - 1); i++) { //Run once for every row
		for (int ii = 0; ii < (colAmount -1); ii++) { //Run once for every column in a row
			//Assign the array value to the next read value
			digitArray[i][ii] = read_row(i, ii);
		
		}
	}
}

//TODO storageArray is wiped at every return, need to find a way to store values
int read_row (int rowNum, int colNum) {
	
	int value = 9999, int isValid = 0;
	int storageArray[colAmount] = {0};
	
	if (colNum == 0) { //If it is the first time the row is being read, print the prompt	
		printf("Enter row %d values (0 - 9, separated by spaces): ", rowNum);
		
		while (!isValid) {
			for (int j = 0; j < (colAmount - 1); j++) { 	
				int inputCache = 9999;
				
				scanf("%d", &inputCache);
				
				if (check_input(inputCache)) {
					storageArray[j] = inputCache;
					isValid = 1;
				
				} else {
					printf("***%d is not an intenger between 0 and 9\nEnter row %d values  (0 - 9, separated by spaces): ", inputCache, colNum);
					
					break; //Exit the for loop if an invalid value is found
					
				}
			}
		}
	}
	
	
		
	
	return value;

}

int check_input (int checkInt) {
	
	if (checkInt >= 0 && checkInt <= 9) {
		return 1; //Return true
	
	} else {
		return 0; //Return false
	
	}

}
