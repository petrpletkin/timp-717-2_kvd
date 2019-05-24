#include "stdio.h"

int main()
{
	unsigned n;
	int temp = 1;
	int num;
	scanf("%u", &n);
	for (int i = 1; i <= n; i++)
	{		
		scanf("%d", &num);
		temp *= num;		
	}
	printf("%d", temp);	
}