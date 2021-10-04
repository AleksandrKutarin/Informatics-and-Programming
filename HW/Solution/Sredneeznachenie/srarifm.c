#include <stdio.h>
#include <math.h>

void main() {
	int a, b, c;
	float A;
	scanf_s("%d %d %d %f", &a, &b, &c, &A);
	A = (a + b + c) / 3;
	printf("%0.1f", A);
}