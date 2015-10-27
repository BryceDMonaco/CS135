/*
	Bryce Monaco
	CS135-1201
	
	Program 3 - Challenge
	Computes the sum of squares between 1 and any number

*/

#include <stdio.h>

int main (void) {
	int n, returnValue;
	
	printf("Please enter the value n for the sum of squared series: ");
	scanf("%d", &n);
	
	returnValue = sum_squares(n);
	
	printf("The sum of squares from 1 to %d is: %d\n", n, returnValue);
	
	return 0;
	

}

//A recursive function to calculate the sum
int sum_squares (int n) {
	int valueSum = 0;
	
	if (n > 1) {
		valueSum = (n*n) + sum_squares((n-1));	
		
		return valueSum;
		
	} else if (n == 1) {
		return 1;
	
	}

}
