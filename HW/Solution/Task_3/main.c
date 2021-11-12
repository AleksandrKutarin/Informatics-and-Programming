//Copyright Aleksandr Kutarin
#include <stdio.h>
#include <time.h>
#include <math.h>
#include<malloc.h>
#include<locale.h>

int getNum(int size);
void convertToArr(int* arr, int size, int n);
int countTarget(int* arr1, int* arr2, int size);
int countPosTarget(int* arr1, int* arr2, int size);

int main() {

	setlocale(LC_ALL, "Russian");

	int size, *secretNum;
	printf("Введите число в диапозоне от 2 до 5: ");
	scanf_s("%d", &size);
	secretNum = (int*) malloc(size * sizeof(int*));
	int rnd = getNum(size);

	convertToArr(secretNum, size, rnd);

	int a = -1;
	int b = -2;
	int answer = -1, *answerArr;
	answerArr = (int*)malloc(size * sizeof(int*));
	while (rnd != answer) {
		printf("Попробуйте угадать число состоящие из %d знаков: ", size);
		scanf_s("%d", &answer);
		convertToArr(answerArr, size, answer);
		a = countTarget(secretNum, answerArr, size);
		b = countPosTarget(secretNum, answerArr, size);
		printf("Количество верно угаданных чисел: %d\n", a);
		printf("Количество верно угаданных позиций: %d\n", b);
	}
	printf("Загаданное число %d\n", rnd);
	printf("Game Over");
	return 0;
}

int getNum(int size) {
	int upper, lower;
	srand(time(NULL));
	upper = pow(10, size);
	lower = pow(10, size - 1);

	int r = (rand() % (upper - lower)) + lower;
	return  r;
}

void convertToArr(int* arr, int size, int n) {
	for (int i = size - 1; i >= 0; i--) {
		arr[i] = n % 10;
		n = n / 10;
	}
	printf("\n");
}

int countTarget(int* arr1, int* arr2, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr2[i] == arr1[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}

int countPosTarget(int* arr1, int* arr2, int size) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr2[i] == arr1[i])
			count++;
	return count;
}