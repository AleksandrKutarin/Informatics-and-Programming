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
		printf("������� �����: ");
		scanf_s("%d", &a);
		if (a > b)
		{
			printf("������\n");
		}else if (a < b)
		{
			printf("������\n");
		}	
	} while (a != b);
	printf("WIN");
	getchar;
}