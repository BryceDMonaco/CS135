/*
	Bryce Monaco
	CS135-1002, CS135-1201
	
	Compile with "gcc convert.c -o convert"
*/

#include <stdio.h>

int main (void) {

	float mphSpeed;	
	
	printf("Please enter a speed in miles per hour: ");
	scanf("%f", &mphSpeed);
	
	printf("%.001f MPH is %.3f m/s\n", mphSpeed, (mphSpeed * 0.44704f)); //0.44704 m/s = 1 MPH
	
	return 0;
}
