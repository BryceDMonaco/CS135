/*
	Bryce Monaco
	CS135 - 1201
	Project 6 - Assignment 2
	
	Compile with "gcc data_storage.c -std=c99 -o stor"
	
*/

#include <stdio.h>
#include <stdlib.h>

void WriteInt (int mode, int nameLength, char fileName[nameLength]);
void WriteChar (int mode, int nameLength, char fileName[nameLength]);
void PrintWarning ();

int main (int argc, char *argv[])
{
	int qual, mode, fileLength = 0, filePos; //qual 0 = c, 1 = n mode 0 = a, 1 = o
	
	if (argc == 1) //If the user didn't give any arguments
	{
		PrintWarning();
		
		exit(0);
		
	} else if (argc != 4)
	{
		PrintWarning();
		
		exit(0);
	
	} else if (argc == 4)
	{
		for (int i = 1; i < 4; i++)
		{
			if (argv[i][0] == '-')
			{
				if (argv[i][1] == 'c')
				{
					qual = 0;
				
				} else if (argv[i][1] == 'n')
				{
					qual = 1;
				
				} else if (argv[i][1] == 'a')
				{
					mode = 0;
				
				} else if (argv[i][1] == 'o')
				{
					mode = 1;
				
				}
			
			} else
			{
				filePos = i;
				
				while (argv[i][fileLength] != '\0')
				{
					fileLength++;
				
				}
				
				fileLength++; //To include the null character
			
			}
		
		}
	
	}
	
	char fileName[fileLength];
	
	for (int i = 0; i < fileLength; i++)
	{
		fileName[i] = argv[filePos][i];
	
	}
	
	if (qual == 0 && mode == 0)//-c with -a
	{
		WriteChar(0, fileLength, fileName);
	
	} else if (qual == 0 && mode == 1) //-c with -o
	{
		WriteChar(1, fileLength, fileName);
	
	} else if (qual == 1 && mode == 0) //-n with -a
	{
		WriteInt(0, fileLength, fileName);
	
	} else if (qual == 1 && mode == 1) //-n with -o
	{
		WriteInt(1, fileLength, fileName);
	
	}
	
	printf("DEBUG: qual: %d mode: %d length: %d\n", qual, mode, fileLength);
	
	return 0;
	
}

void WriteChar (int mode, int nameLength, char fileName[nameLength])
{
	printf("%s\n", fileName);
	
	FILE *f;
	
	if (mode == 0) //Append
	{
		f = fopen(fileName, "a");
	
	} else if (mode == 1)
	{
		f = fopen(fileName, "w");
	
	}
	
	int amount;
	
	printf("Enter the amount of character you want to enter: ");
	scanf(" %d", &amount);
	
	printf("Enter the string, max of %d characters: ", amount);
	
	char *str;
	
	str = (char *) malloc((amount + 2) * sizeof(char));
	
	for (int i = 0; i < (amount); i++)
	{
		scanf(" %c", &str[i]);
		
	}
	
	str[amount] = '\n';
	
	printf("%s\n", str);
	
	fprintf(f, "%s", str);
	
	fclose(f);
	
}

void WriteInt (int mode, int nameLength, char fileName[nameLength])
{
	printf("%s\n", fileName);
	
	FILE *f;
	
	if (mode == 0) //Append
	{
		f = fopen(fileName, "ab");
	
	} else if (mode == 1)
	{
		f = fopen(fileName, "wb");
	
	}
	
	int amount;
	
	printf("Enter the amount of integers you want to enter: ");
	scanf(" %d", &amount);
	
	printf("Enter the numbers, spaces between, max of %d numbers: ", amount);
	
	int *str;
	
	str = (int *) malloc((amount + 2) * sizeof(int));
	
	for (int i = 0; i < (amount); i++)
	{
		scanf(" %d", &str[i]);
		
		fprintf(f, "%d ", str[i]);
		
	}
	
	fclose(f);
	
}

void PrintWarning ()
{
	printf("Usage: data_storage (-c or -n) (-o or -a) (filename).txt\n");
	printf("-c to enter characters\n-n to enter integers\n");
	printf("-a to append to the named file\n-o to overwrite to the named file\n");

}
