// algorithms for generating pi 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double dist(int a, int b)
{
	return sqrt(a*a + b*b);
}
	
// naive algorithm for approximating pi
// imagine a 1000 x 1000 square
// a circle of radius 500 can be inscribed in the square

double naivePi(int n)
{
	double in_circ = 0;
	double in_square = 0;
	for (int i = 0; i < n; i++)
	{
		int a = rand()%1000;
		int b = rand()%1000;

		if (dist(a - 500,b - 500) < 500)
			in_circ++;
		else
			in_square++;
	}

	return in_circ/in_square;
}


// uses Viete's formula to calculate pi
// much better than naive

double vietePi()
{
	return 768 * sqrt(2 - sqrt(2 + sqrt(2 + sqrt(2 + sqrt(2 + sqrt(2 + sqrt(2 + sqrt(2 + sqrt(2 + 1)))))))));
}

int main(int argc, char *argv[])
{
	srand (time(NULL));
	printf("Naive Pi approximation: %lf \n", naivePi(10000));
	printf("Viete's formula: %lf \n", vietePi());
	return 0;
}