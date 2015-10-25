/*
	Bryce Monaco
	
	This was a simple program written to help study calculus. The program will
	randomly generate an amount of polynomials in the form of "ax^2+bx+c"

*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int loopCode = 0;
	
	while(1 > 0) {
		
		//Mod 20 to output a random number between [0, 19]
		int firstCoef = rand() % 20, secondCoef = rand() % 20, thirdCoef = rand() % 5;
		
		//Check for coefficients of 0 and output accordingly
		if (firstCoef == 0) {
			if (secondCoef == 0) {
				printf("f(x) = %d (Constant Function)\n\n", thirdCoef);
				
			} else if (thirdCoef == 0) {
				printf("f(x) = %dx\n\n", secondCoef);
				
			} else if (secondCoef == 0 && thirdCoef == 0) {
				printf("f(x) = 0 (Constant Function)\n\n");
				
			} else {
				printf("f(x) = %dx+%d\n\n", secondCoef, thirdCoef);
				
			}
			
		} else if (secondCoef == 0) {
			if (thirdCoef == 0) {
				printf("f(x) = %dx^2\n\n", firstCoef);
				
			} else {
				printf("f(x) = %dx^2+%d\n\n", firstCoef, thirdCoef);
				
			}
			
		} else if (thirdCoef == 0) {
			printf("f(x) = %dx^2+%dx\n\n", firstCoef, secondCoef);
			
		} else {
			printf("f(x) = %dx^2+%dx+%d\n\n", firstCoef, secondCoef, thirdCoef);
				
		}
		
		printf("Input any number to re-generate, input 0 to end: ");
		scanf("%d", &loopCode);
		
		if (loopCode == 0) {
			break;
			
		}
	}
	
	return 0;
}
