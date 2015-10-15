/*
	Bryce Monaco
	CS135-1002, CS135-1201
	
	Compile with "gcc interest.c -o interest -lm"
*/

#include <stdio.h>
#include <math.h>

int main (void) {
	float principalAmt, interestAmt, compoundAmt;
	int yearCounter;
	
	printf("Please enter the amount of principal and interest percentage: ");
	scanf("%f %f", &principalAmt, &interestAmt);
	
	interestAmt = interestAmt/100.0;
	
	while (yearCounter < 20) {
		yearCounter++;
		
		compoundAmt = principalAmt * powf((1.0 + (interestAmt / 1)), yearCounter);
		
		printf("%d\t$%.2f\n", (yearCounter - 1), compoundAmt);
	}
	
	return 0;
}
