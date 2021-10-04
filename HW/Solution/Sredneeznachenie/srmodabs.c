#include <stdio.h>
#include <math.h>
void main(){
	int a, b, c;
	float x;
	scanf_s("%d %d %d %f", &a, &b, &c, &x);
	x = (abs(a) + abs(b) + abs(c)) / 3;
	printf("%0.1f", x);
}