//copyraigyt Aleksandr Kutarin
#include<stdio.h>
#include<locale.h>
#include<time.h>

int main() {

	setlocale(LC_ALL, "Russian");

	/*�������� ��������� ������������ �����, ��� ������������ ������ ��� �������� � ������ �������, ��� ������������ ���������� ����� � ��������� ��� ���������*/
	int a, b, k = 0;
	int VARIANT;
	int CHr, CHp, popytki = 0;
	int MIN = 1, MAX = 1000;
	char BOLMENRAV;
	printf("������� ������� 1 ��� 2 : ");
	scanf_s("%d", &VARIANT);
	switch (VARIANT)
	{
	case 1:
	{
		srand(time(NULL));
		b = rand() % 1000 + 1;
		do
		{
			printf("������� �����: ");
			scanf_s("%d", &a);
			if (a > b)
			{
				k++;
				printf("������\n");
			}
			else if (a < b)
			{
				k++;
				printf("������\n");
			}
		} while (a != b);
		printf("WIN, ������� ������������� = %d", k);
	}break;
	printf("\n������ ����� ��������� �����\n");
	case 2: {
		srand(time(NULL));
		CHr = rand() % 1000 + 1;
		printf("\n������������ ������� �����: \n");
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
				printf("WIN, ��������� ������� = %d", popytki);
				break;
			}
		}
	}
	}
	getchar();
	return 0;
}