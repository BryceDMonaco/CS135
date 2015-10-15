/*
	Bryce Monaco
	CS135-1201
	
	Scramble Sentence
	
	Compile with: gcc scramble_sentence.c -o scram -std=c99
*/

#include <stdio.h>

int main (void) {

	int charCount = 0, spaceCount = 0, printedSpaceCount = 0;
	int spaceLocation[500] = {999}; //used to store charCount number when there is a space, 999 is a value that will never happen, will be less than 500
	
	char word[500] = {'\0'};
	char finalSymbol;
	
	printf("Enter a sentence ended by a '.', a '?', or a '!' (less than 500 chars): ");
	
	for (int i = 0; i < 500; i++) {
		word[i] = getchar();
		charCount++;
		
		if (word[i] == '!' || word[i] == '?' || word[i] == '.') {
			spaceLocation[spaceCount] = charCount; //Counting '!' as a space
			
			spaceCount++;
			
			finalSymbol = word[i];
			
			break;
		
		} else if (word[i] == ' ') {
			spaceLocation[spaceCount] = charCount;
			
			spaceCount++;
		
		}
		
		if (i == 499) {
			printf("CAUTION: Max input length reached, last read character is '%c'\n", word[i]);
			
		}
	}
	
	printf("\nReversed sentence:");
	
	//Word for loop, completes when the current word is printed and a space is reached
		//Characters in a word for loop, completes when a letter is printed and runs until the last letter printed is 1-(next space position)
	//Calculate next space position
	
	int nextSpaceLocation, lastSpaceLocation, wordEndLocation, currentChar = 0, wordLength;
	
	//Word for loop, to write words backwards it needs to start at spaceCount and go to zero
	for (int i = spaceCount; i >= 0; i--) {
		nextSpaceLocation = spaceLocation[i];
		
		if (i == 0) {
			lastSpaceLocation = 0; //The first word input has no space before it, so the 0th character acts as its space
			
			wordLength = nextSpaceLocation - lastSpaceLocation; //The lastSpaceLocation is redundant because it equals 0
		
		} else {
			lastSpaceLocation = spaceLocation[i - 1]; //The word starts at the space before
			
			wordLength = (nextSpaceLocation - lastSpaceLocation) - 1;
			
		}
		
		for (int ii = 0; ii < wordLength; ii++) {
			//currentChar = ii + lastSpaceLocation;
			
			if (ii == (wordLength - 2) && i == 0 && wordLength != 1) {
				ii += 1;
				//printf("BANG"); Debug to test if the statement fires
			
			}
			
			if (ii < 2 && wordLength != 1) {
				currentChar = nextSpaceLocation + (ii - 3);
			
			} else if (wordLength != 1) {
				currentChar = (ii - 2) + lastSpaceLocation;
			
			} else if (wordLength == 1) {
				currentChar = 1 + lastSpaceLocation;
			
			}
			
			if (ii - 1 == (wordLength - 2) && i == 0 && wordLength != 1) {
				currentChar -= 1;
				//printf("BAMBAM"); Debug to test if the statement fires
			
			}
			
			if (word[currentChar] != ' ') {
				putchar(word[currentChar]);
				
			} else if (word[currentChar] == ' ') {
				//do nothing and continue the loop, unsure if a break would stop the loop completely
			
			}
			
		}
		
		//printf("WL:%d", wordLength); Debug
		
		if (wordLength == 1) {
			putchar(word[currentChar - 1]);
		
		}
		
		
		if (i == spaceCount) { //If the last input word is being printed, do not print the exclaimation point
			putchar(' ');
		
		} else if (i == 0) { //else if the first input word is being printed, end it with an exclaimation point
			putchar(finalSymbol);
		
		} else {
			putchar(' ');
		
		}
		
	}
	
	printf("\n\n------------Debug Info------------");
	
	printf("\nThere is a space at char number: ");
	
	while (printedSpaceCount < spaceCount) {
		printf("%d ", spaceLocation[printedSpaceCount]);
		
		printedSpaceCount++;
		
	}
	
	printf("\nTotal words: %d\n", spaceCount + 1);
	
	return 0;
}
