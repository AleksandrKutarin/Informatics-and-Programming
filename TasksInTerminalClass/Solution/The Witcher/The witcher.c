#include<stdio.h>
#include<locale.h>

void main() {
	setlocale(LC_ALL, "rus"); 
	int a = 1, b = 5, c = 10, d = 25;
	int Ca1 = 0, Cb5 = 0, Cc10 = 0, Cd25 = 0;
	int Dengi; 
	float sum;
	printf("ценна за услуги Ведьмака: Dengi");
	scanf_s("%d", &Dengi);
	sum = 0;
	while (sum != Dengi) {
		if (d + sum <= Dengi)
		{
			sum += d;
			Cd25 += 1;
		}
		else if (c + sum <= Dengi)
		{
			sum += c;
			Cc10 += 1;
		}
		else if (b + sum <= Dengi)
		{
			sum += b;
			Cb5 += 1;
		}
		else if (a + sum <= Dengi)
		{
			sum += a;
			Ca1 += 1;
		}
	}
	printf("%d %d %d %d", Ca1, Cb5, Cc10, Cd25);
	return 0;
}