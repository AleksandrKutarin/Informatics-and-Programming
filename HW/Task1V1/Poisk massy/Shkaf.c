#include<stdio.h>
#include<locale.h>
#include<math.h>

void main() {

	setlocale(LC_ALL, "Russian");

	int h, w, d, cm;
	int pDSP = 550; //��������� ���
	int pDVP = 800; // ��������� ���
	int pDerevo = 1000; // ��������� ���������� �����
	int polki; // �����
	float mDVP, bDSP, kDSP, mDver, mPolki, m;
	cm = 1000000;// plotnost

	printf("������� ������: ");
	scanf_s("%d", &h);

	printf("������� ������: ");
	scanf_s("%d", &w);

	printf("������� �������: ");
	scanf_s("%d", &d);

	polki = h / 40;
	mDVP = ((h * w * 0.5) / cm) * pDVP;
	bDSP = ((h * d * 1.5) / cm) * pDSP * 2;
	kDSP = ((w * d * 1.5) / cm) * pDSP * 2;
	mDver = ((h * w) / cm) * pDerevo * 2;
	mPolki = ((w * d * 1.5) / cm) * pDSP * polki;
	m = mDVP + bDSP + kDSP + mDver + mPolki;
	printf("����� �����: %f", m);
}