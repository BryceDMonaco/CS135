/*
	Bryce Monaco
	
	See README.txt for program information

*/

#include <stdio.h>

void getArrayInput (int size, int arr[size]);
void reverseArray (int size, int arr[size]);

int main (void) {
	int arraySize;
	
	printf("Enter the size of the array: ");
	scanf("%d", &arraySize);
	
	int intArray[arraySize];
	
	getArrayInput(arraySize, intArray);
	
	printf("Current array is:\n");
	
	for (int i = 0; i < arraySize; i++) {
		printf("\t%d", intArray[i]);
	
	}
	
	printf("\n");
	
	reverseArray(arraySize, intArray);
	
	printf("Reversed array is:\n");
	
	for (int i = 0; i < arraySize; i++) {
		printf("\t%d", intArray[i]);
	
	}
	
	printf("\n");
	
	return 0;

}

void getArrayInput (int size, int arr[size]) {
	printf("Enter %d numbers, separated by spaces: ", size);
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	
	}
	
	return;

}

void reverseArray (int size, int arr[size]) {
	int tempArray[size];
	
	for (int i = 0; i < size; i++) {
		tempArray[i] = arr[size - (i+1)];
	
	}
	
	for (int i = 0; i < size; i++) {
		arr[i] = tempArray[i];
	
	}
	
	return;

}
