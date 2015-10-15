/*
	Bryce Monaco
	CS135-1201
	
	Magic Square
	
	Compile with: gcc magic_square.c -o magic -std=c99
*/

#include <stdio.h>

int main (void) {
	
	int squareSize = 2, nextValue = 0; //squareSize needs to be an odd number
	
	while (squareSize % 2 != 1) {
		printf("An odd number is needed to generate a square.\nPlease enter an odd, positive number: ");
		scanf("%d", &squareSize);
		
		if (squareSize % 2 == 0 || squareSize < 1) {
			printf("~This is not an odd, positive integer~\n");
			
			squareSize = 2;
		
		}
	}
	
	int squareAmount = squareSize * squareSize;
	int magic[squareSize][squareSize];
	int currentCol = (squareSize / 2), currentRow = 0, valueInterval = 0;
	
	//Fill the array with placeholder values
	for (int i = 0; i < squareSize; i++) {
		for (int ii = 0; ii < squareSize; ii++) {
			magic[i][ii] = 9999; //9999 is a placeholder value
		
		}
	
	}
	
	printf("\n");
	
	for (int i = 0; i < squareAmount; i++) {
		
		//printf("loop[%d]\n", i); This is a debug output, uncomment to view output
		
		if (magic[currentRow][currentCol] == 9999) { //if the value hasn't been changed
			magic[currentRow][currentCol] = i + 1;
			
			//printf("\tmagic[%d][%d] = %d\n", currentRow, currentCol, magic[currentRow][currentCol]); This is a debug output, uncomment to view output
			
		} else if (magic[currentRow][currentCol] != 9999) {
			
			while (magic[currentRow][currentCol] != 9999) { //Run a loop to keep checked for an open value		
				//printf("\tValue detected at [%d][%d]\n", currentRow, currentCol); This is a debug output, uncomment to view output
				
				//if the value is already written, move down one row
				if (currentRow != (squareSize - 1)) {
					currentRow += 1;
		
				} else if (currentRow == (squareSize - 1)) { //if currentRow equals 0, wrap to bottom
					currentRow = 0;
		
				}
			}
			
			magic[currentRow][currentCol] = i + 1;	
			
			//printf("\tmagic[%d][%d] = %d\n", currentRow, currentCol, magic[currentRow][currentCol]); This is a debug output, uncomment to view output
			
		}
		
		if (i == 0) {
			//Move up one row
			if (currentRow != 0) {
				currentRow -= 1;
		
			} else { //if currentRow equals 0, wrap to bottom
				currentRow = squareSize - 1;
		
			}
		
			//Move to the right one column
			if (currentCol != (squareSize - 1)) {
				currentCol += 1;
		
			} else { //if it is in the right
				currentCol = 0;
		
			}
		
		} else if ((i + 1) % squareSize != 0 && i != 0) {
			//Move up one row
			if (currentRow != 0) {
				currentRow -= 1;
		
			} else { //if currentRow equals 0, wrap to bottom
				currentRow = squareSize - 1;
		
			}
		
			//Move to the right one column
			if (currentCol != (squareSize - 1)) {
				currentCol += 1;
		
			} else { //if it is in the right
				currentCol = 0;
		
			}
		} else if ((i + 1) % squareSize == 0) {
			if (currentRow != (squareSize - 1)) {
				currentRow += 1;
		
			} else if (currentRow == (squareSize - 1)) { //if currentRow equals 0, wrap to bottom
				currentRow = 0;
		
			}
		}
	} 
	
	for (int j = 0; j < squareSize; j++) {
		for (int jj = 0; jj < squareSize; jj++) {
			printf("\t%4d", (magic[j][jj]));
		
		}
	
		printf("\n");	
	
	}
	
	printf("\n");	
	
	return 0;
	
}
