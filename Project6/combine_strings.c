/*
	Bryce Monaco
	CS135 - 1201
	Project 6 - Assignment 1
	
	Compile with "gcc combine_strings.c -std=c99 -o comb"
	
*/

#include <stdio.h>
#include <stdlib.h>

char *intersperse (char str1[32], char str2[32]);
char *widen_stars (char str1[32], char str2[32]);

int main (int argc, char *argv[])
{
	char firstStr[32], secondStr[32], *result;
	
	printf("Please enter a string (30 Character Max.): ");
	scanf(" %30s", firstStr);
	
	printf("Please enter a string (30 Character Max.): ");
	scanf(" %30s", secondStr);
	
	//Debug
	printf("String 1: %s\nString 2: %s with (%s)\n", firstStr, secondStr, argv[1]);
	
	if (strcmp(argv[1], "-i") == 0)
	{
		result = intersperse(firstStr, secondStr);
	
	} else if (strcmp(argv[1], "-w") == 0)
	{
		result = widen_stars(firstStr, secondStr);
	
	}
	
	printf("%s\n", result);
	
	free(result);
	
	return 0;
	
}

char *widen_stars (char str1[32], char str2[32])
{
	int str1Done = 0, str2Done = 0;
	int onChar = 0, strChar = 0;
	
	static char *str;
	str = (char *) malloc(64);
	
	while (str1[onChar] != '\0')
	{
		str[strChar] = str1[onChar];
		
		strChar++;
		onChar++;
		
		str[strChar] = '*';
		
		strChar++;
		
	}
	
	onChar = 0;
	
	while (str2[onChar] != '\0')
	{
		str[strChar] = str2[onChar];
		
		strChar++;
		onChar++;
		
		if (str2[onChar] != '\0')
		{
			str[strChar] = '*';
			
			strChar++;
			
		}
		
	
	}
	
	return str;
	
}

//Combines two strings
//If str1 is "asdf" and str2 is "123456" output is "a1s2d3f456
char *intersperse (char str1[32], char str2[32])
{
	int str1Done = 0, str2Done = 0;
	int onChar = 0, strChar = 0;
	
	static char *str;
	str = (char *) malloc(64);
	
	while (!str1Done || !str2Done)
	{
		if (str1[onChar] == '\0' && !str1Done)
		{
			str1Done = 1;
		
		} else if (str2[onChar] == '\0' && !str2Done)
		{
			str2Done = 1;
		
		}
		
		if (!str1Done)
		{
			//printf("%c", str1[onChar]);
			str[strChar] = str1[onChar];
			
			strChar++;
			
		}
		
		if (!str2Done)
		{
			//printf("%c", str2[onChar]);
			str[strChar] = str2[onChar];
			
			strChar++;
			
		}
		
		onChar++;
	
	}
	
	//Null terminate the newly created string
	if (strChar < 63) //Checks if the string didn't max out (should always happen)
	{
		str[strChar] = '\0';
	
	} else if (strChar == 63) //If it did, replace the last character with a null ter.
	{
		str[63] = '\0';
	
	}
	
	return str;

}
