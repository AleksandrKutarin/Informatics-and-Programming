//copyright Aleksandr Kutarin
#include<stdio.h>
#include<locale.h>
#include<math.h>

int main() {

	setlocale(LC_ALL, "Russian");

	printf("Task with circles");

	float x1, x2, y1, y2, r1, r2;
	float d;
	printf("Введем первую окр через x,y,r: ");
	scanf_s("%f %f %f", &x1, &y1, &r1);

	printf("Введем вторую окр через x,y,r: ");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (d == r1 + r2) {
		printf("окр касаются");
	}
	else if (d < r1 + r2) {
		if (d == 0 && r1 == r2) {
			printf("совпадают");
		}
		if (d + r1 < r2 || d + r2 < r1) {
			printf("Одна окр лежит внутри другой окр");
		}
		else {
			printf("Они пересекаются");
		}
	}else
		if (d > r1 + r2) {
			printf("Окружности не звязаны");
	}
	return 0;
}

