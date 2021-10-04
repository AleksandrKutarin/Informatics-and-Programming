#include <stdio.h>
#include <math.h>

void main() {
	int a, b, c;
	float x;
	scanf_s("%d %d %d %f", &a, &b, &c, &x);
	x = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
	printf("%0.1f", x);
}