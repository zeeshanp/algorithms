#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* usage = "Project Euler #67. Usage: .//euler67 [numRows] [file.txt]\nAuthor: Zeeshan Pirzada\n";

#define MAX(a,b)  (((a) > (b)) ? (a) : (b))

int main(int argc, char** argv)
{
	if (argc != 3)
	{	
		printf("%s", usage);
		return 0;
	}

	int rows = atoi(argv[1]);
	int** tree_array = (int**) malloc(rows * sizeof(int*));
	
	for (int k = 0; k < rows; k++)
		tree_array[k] = (int*) malloc((k+1) * sizeof(int));
	
	FILE *fp = fopen(argv[2], "r");
	char c;
	int i = 0;
	int j = 0;

	//read file into tree_array
	while ((c = getc(fp)) != EOF)
	{
		if (c == ' ' || c == '\n')
			continue;
		
		int tens = c - '0';
		c = getc(fp);
		int ones = c - '0';
		int toAdd = 10*tens + ones;
		tree_array[i][j++] = toAdd;
		
		if (j == i + 1)
		{
			i++;
			j = 0;	
		}
	}



	//opt[i][j] contains optimal solution for the jth number in the ith row.

	int** opt = (int**) malloc(rows * sizeof(int*));
	for (int k = 0; k < rows; k++)
		opt[k] = (int*) malloc((k+1) * sizeof(int));
	
	
	//maximal path to bottom row is just that number.
	for (int k = 0; k < rows; k++)
	{
		opt[rows-1][k] = tree_array[rows-1][k];
	}


	//compute bottom up answers.
	for (int k = rows - 2; k >= 0; k--)
	{
		for (int l = 0; l <= k; l++)
		{
			opt[k][l] = tree_array[k][l] + MAX(opt[k+1][l], opt[k+1][l+1]);
		}
	}


	printf("The answer is: %d\n.", opt[0][0]);
	return 0;
}

