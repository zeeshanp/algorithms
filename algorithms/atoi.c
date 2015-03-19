// convert c string to int

#include <stdio.h>
#include <ctype.h>


int atoi(char *c)
{
	int ret = 0;
	int neg = 0;
	while (*c != '\0')
	{
		if (*c == '-')
		{
			neg = 1;
		}
		else if (isdigit(*c))
		{
			ret = 10*ret + (int)(*c - '0');
		}
		else
		{
			printf("Improper format for number\n");
			return -1;
		}
		c++;
	}
	if (neg)
		return -1*ret;
	return ret;
}
