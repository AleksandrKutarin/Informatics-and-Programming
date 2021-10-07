#include <stdio.h>
#include <math.h>


void main() {
	//sr kv kornya
	int a, b, c;
	float x;
	scanf_s("%d %d %d %f", &a, &b, &c, &x);
	x = (sqrt(a) + sqrt(b) + sqrt(c)) / 3;
	printf("%0.1f", x);
	//modul
	int ma, mb, mc;
	float mx;
	scanf_s("%d %d %d %f", &ma, &mb, &mc, &mx);
	mx = (abs(ma) + abs(mb) + abs(mc)) / 3;
	printf("%0.1f", mx);
	//koren is kvadrata
	int ka, kb, kc;
	float kx;
	scanf_s("%d %d %d %f", &ka, &kb, &kc, &kx);
	kx = sqrt(pow(ka, 2) + pow(kb, 2) + pow(kc, 2));
	printf("%0.1f", kx);
	//sr znach
	int sa, sb, sc;
	float sA;
	scanf_s("%d %d %d %f", &sa, &sb, &sc, &sA);
	sA = (sa + sb + sc) / 3;
	printf("%0.1f", sA);
	//okr
	int r;
	double Pi = 3.14;
	int S;
	scanf_s("%d %d", &r, &Pi);
	S = Pi * r * r;
	printf("%d", S);
	//pryamougl
	int pa, pb;
	int pS;
	scanf_s("%d %d", &pa, &pb);
	pS = pa * pb;
	printf("%d", pS);
	//treugolnik
	int ha, hb;
	int hS;
	scanf_s("%d %d", &ha, &hb);
	hS = 0.5 * ha * hb;
	printf("%d", hS);
}