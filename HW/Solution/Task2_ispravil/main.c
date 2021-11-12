//copyraigyt Aleksandr Kutarin
#include<stdio.h>
#include<locale.h>
#include<time.h>

int main() {

	setlocale(LC_ALL, "Russian");

	/*написать программу загадывающую число, где пользователь должен его отгадать и второй вариант, где пользователь загадывает число и компьютер его угадывает*/
	int a, b, k = 0;
	int VARIANT;
	int CHr, CHp, popytki = 0;
	int MIN = 1, MAX = 1000;
	char BOLMENRAV;
	printf("выбрать вариант 1 или 2 : ");
	scanf_s("%d", &VARIANT);
	switch (VARIANT)
	{
	case 1:
	{
		srand(time(NULL));
		b = rand() % 1000 + 1;
		do
		{
			printf("Введите число: ");
			scanf_s("%d", &a);
			if (a > b)
			{
				k++;
				printf("меньше\n");
			}
			else if (a < b)
			{
				k++;
				printf("больше\n");
			}
		} while (a != b);
		printf("WIN, попыток использованно = %d", k);
	}break;
	printf("\nТеперь робот угадывает число\n");
	case 2: {
		srand(time(NULL));
		CHr = rand() % 1000 + 1;
		printf("\nПользователь загадал число: \n");
		scanf_s("%d", &CHp);
		CHr = (rand() % (MAX - MIN + 1) + MIN);
		printf("%d", CHr);
		while (CHr != CHp) {
			scanf_s("%c", &BOLMENRAV);
			if (BOLMENRAV == '<') {
				MAX = CHr;
				CHr = (rand() % (MAX - MIN + 1) + MIN);
				printf("%d\n", CHr);
				popytki++;
			}
			if (BOLMENRAV == '>') {
				MIN = CHr;
				CHr = (rand() % (MAX - MIN + 1) + MIN);
				printf("%d\n", CHr);
				popytki++;
			}
			if (CHr == CHp) {
				printf("WIN, Потрачено попыток = %d", popytki);
				break;
			}
		}
	}
	}
	getchar();
	return 0;
}