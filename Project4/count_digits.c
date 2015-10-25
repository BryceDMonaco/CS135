/*
	Bryce Monaco
	CS135-1201
	
	Count Digits (Assignment 1)
	
	Compile with: gcc count_digits.c -o count -std=c99
*/

#include <stdio.h>

	//Initialize and assign values that allow the while loop to run at least once
	//Woo globals
	int colAmount = -1, rowAmount = -1;
	int storageArray[500] = {0}; //This is needed to store any input
	int intOccurance[10] = {0}; //Will be used at the end to count the occurance of 0 - 9
	
//Function Declarations
int read_row (int rowNum, int colNum);
int check_input (int checkInt);
int compute_row_count (int value);
int print_total_count (int countArray[10]); 

int main (void) {
	
	//Fill storageArray with placeholder values
	for (int i = 0; i < 500; i++) {
		storageArray[i] = 9999;
	
	}
	
	
	printf("This program counts occurrences of digits 0 through 9 in an NxM array\n");
	printf("Enter the size of your array (\"N M\"): ");
	
	//Keep waiting for values that fufill the conditions
	while (!(colAmount >= 0) && !(rowAmount >= 0)) {
		scanf("%d %d", &rowAmount, &colAmount);
		
		if ((colAmount >= 0) && (rowAmount >= 0)) {
			printf("Making an array with %d rows and %d columns.\n", rowAmount, colAmount);
		
		} else {
			printf("Invalid array size. Ensure both values are >= 0 and are integers.\n");
			printf("Enter the size of your array (\"N M\"): ");
			
		}
	}
	
	//Create the array and fill it with zeroes
	int digitArray[rowAmount][colAmount];
	
	//Fill the array with placeholder values
	for (int i = 0; i < (rowAmount); i++) {
		for (int ii = 0; ii < (colAmount); ii++) {
			digitArray[i][ii] = 9999; //9999 is a placeholder
		
		}
	}
	
	//Loop to call read_row
		//
	for (int i = 0; i < (rowAmount); i++) { //Run once for every row
		for (int ii = 0; ii < (colAmount); ii++) { //Run once for every column in a row
			//Assign the array value to the next read value
			digitArray[i][ii] = read_row(i, ii);
			
			//Pass the value to compute_row_count
			compute_row_count(digitArray[i][ii]);
		}
	}
	
	printf("\n");
	
	for (int i = 0; i < rowAmount; i++) {
		for (int ii = 0; ii < colAmount; ii++) {
			printf("\t%d", digitArray[i][ii]);
		
		}
		
		printf("\n");
		
	}
	
	print_total_count(intOccurance);
	
	return 0;
	
}

int read_row (int rowNum, int colNum) {
	
	int value = 9999, isValid = 0;
	
	if (colNum == 0) { //If it is the first time the row is being read, print the prompt	
		printf("Enter row %d values (0 - 9, separated by spaces): ", rowNum);
		
		while (!isValid) {
			for (int j = 0; j < (colAmount); j++) { 	
				
				//printf("Scanning[j%d] ", j); Debug output
				
				int inputCache = 9999;
				
				scanf("%d", &inputCache);
				
				if (check_input(inputCache)) {
					storageArray[j] = inputCache;
					
					if (j == (colAmount-1)) { //If the final number has been parsed successfully, stop the loop
						isValid = 1;
					
					}
					
				} else {
					printf("***%d is not an intenger between 0 and 9***\nEnter row %d values  (0 - 9, separated by spaces): ", inputCache, rowNum);
					
					isValid = 0;
					
					//The remaining values need to be scanned in so that they don't get
					//picked up in a later scanf
					int remainingDump = 0;
					
					for (int jj = 0; jj < (colAmount - j - 1); jj++) {
						scanf("%d", &remainingDump);
						
					} 
					
					break; //Exit the for loop if an invalid value is found
					
				}
			}
		}
	}
	
	return storageArray[colNum];

}

//A function to check if the integer input is between 0 and 9 inclusively
int check_input (int checkInt) {
	
	if (checkInt >= 0 && checkInt <= 9) {
		return 1; //Return true
	
	} else {
		return 0; //Return false
	
	}
}

//A function to count the amount of times each integer between 0 - 9 occurs
int compute_row_count (int value) {
	intOccurance[value] += 1;

}

int print_total_count (int countArray[10]) {
	printf("Total count for each digit:\n");
	
	for (int ii = 0; ii < 10; ii++) {
		if (countArray[ii] > 1 || countArray[ii] == 0) {
			printf("Digit %d occurs %d times.\n", ii, countArray[ii]);
		
		} else {
			printf("Digit %d occurs %d time.\n", ii, countArray[ii]);
		
		}
	}
	
	return 1; //Just to return a value, should be discarded

}
