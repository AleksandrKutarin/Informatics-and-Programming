#include<stdio.h>
#include<locale.h>
#include<math.h>

void main(){

	setlocale(LC_ALL, "Russian");

	int h, w, d;
	int pDSP = 550;
	int pDVP = 800;
	int pDerevo = 1000;
	int polki;
	float mDVP, bDSP, kDSP, mDver, mPolki, m;

	printf("Введите высоту: ");
	scanf_s("%d", &h);

	printf("Введите ширину: ");
	scanf_s("%d", &w);

	printf("Введите глубину: ");
	scanf_s("%d", &d);

	polki = h / 40;
	mDVP = ((h * w * 0.5) / 1000000) * pDVP;
	bDSP = ((h * d * 1.5) / 1000000) * pDSP * 2;
	kDSP = ((w * d * 1.5) / 1000000) * pDSP * 2;
	mDver = ((h * w) / 1000000) * pDerevo * 2;
	mPolki = ((w * d * 1.5) / 1000000) * pDSP * polki;
	m = mDVP + bDSP + kDSP + mDver + mPolki;
	printf("Масса шкафа: %f", m);
}
	

	


	

