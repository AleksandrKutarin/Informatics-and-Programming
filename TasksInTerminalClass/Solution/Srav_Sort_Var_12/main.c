//Copyright Aleksandr Kutarin
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <malloc.h>
#include<locale.h>

void shell_sort(int* array, int size) {

	int* d, k;
	d = (int*)malloc((1 + size / 3) * sizeof(int));

	for (k = 0; k < size / 3; k++) {
		if (k % 2 == 0)
			d[k] = 9 * (int)pow(2, k) - 9 * (int)pow(2, k / 2) + 1;
		else
			d[k] = 8 * (int)pow(2, k) - 6 * (int)pow(2, (k + 1) / 2) + 1;
		if (3 * d[k] > size)
			break;
	}

	for (int s = k - 1; s >= 0; s--) {
		for (int i = d[s]; i < size; ++i) {
			for (int j = i - d[s]; j >= 0 && array[j] > array[j + d[s]]; j -= d[s]) {
				int temp = array[j];
				array[j] = array[j + d[s]];
				array[j + d[s]] = temp;
			}
		}
	}
}

void shake_sort(int* a, int n) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		for (int i = right; i > left; i--)
			if (a[i] < a[i - 1]) {
				int tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
			}
		left++;
		for (int i = left; i < right; i++)
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		right--;
	}
}

void count_sort(int* a, int n, int m) {
	int* b;
	b = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < n; i++)
		b[a[i] - 1]++;

	int j = 0;

	for (int i = 0; i < m; i++)
		while (b[i] > 0) {
			a[j] = i;
			b[i]--;
			j++;
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	int m;
	printf("введите размер:");
	scanf_s("%d", &n);
	printf("введите диапазон:");
	scanf_s("%d", &m);

	int* a;
	a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		a[i] = (rand() % m) + 1;

	double time_spent = 0.0;
	clock_t begin = clock();
	shell_sort(a, n);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nThe Shell sorting time: %f seconds", time_spent);

	time_spent = 0.0;
	begin = clock();
	shake_sort(a, n);
	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nThe Shake sorting time: %f seconds", time_spent);

	time_spent = 0.0;
	begin = clock();
	count_sort(a, n, m);
	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nThe Count sorting time: %f seconds", time_spent);
	return 0;
}