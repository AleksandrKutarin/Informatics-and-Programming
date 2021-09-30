#include<stdio.h>
#include<math.h>
#include<locale.h>

void main() 
{
	setlocale(LC_ALL, "rus");
	int a, b;
	srand(time(NULL));
	b = rand() % 1000 + 1;
	do 
	{
		printf("¬ведите число: ");
		scanf_s("%d", &a);
		if (a > b)
		{
			printf("меньше\n");
		}else if (a < b)
		{
			printf("больше\n");
		}	
	} while (a != b);
	printf("WIN");
	getchar;
}