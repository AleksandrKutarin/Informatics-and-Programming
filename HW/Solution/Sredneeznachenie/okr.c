#include <stdio.h>
#include <math.h>
void main()
{
	int r;
	float M_PI;
	int S;
	scanf_s("%d %0.2f", &r, &M_PI);
	S = M_PI * r * r;
	printf("%d", S);
}