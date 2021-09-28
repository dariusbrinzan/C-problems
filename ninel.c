#include <stdio.h>

// functii pentru max - min
int max(int a, int b)
{    return ((a > b) ? a : b);
}

int min(int b, int a)
{	return ((a < b) ? a : b);
}

int main(void)
{   int n, x_00 = 0, x_01 = 0, x_02 = 0, count = 0;
	int xmax_impar = 0, xmin_par = 0;
	long sum = 0;
// citesc numarul de copaci
	scanf("%d", &n);
	xmin_par = 1000000;
// citesc copacii
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x_00);
// verific daca variabilele x_00 ,  x_01 , x_02 sunt diferite de 0 si le compar
		if (x_00 && x_02 && x_01 && x_01 > x_00 && x_01 > x_02) {
// daca da - fac suma copacilor speciali si ii numar
			sum = sum + x_01;
			++count;
// daca pozitia este impara fac minimul daca este para fac maximul
			if (i % 2)
				xmin_par = min(xmin_par, x_01);
			else
				xmax_impar = max(xmax_impar, x_01);
		}
// retin ultimele 3 numere constant
		x_02 = x_01;
		x_01 = x_00;
	}
// initializez o variabila double pentru a calcula media aritmetica
	double m_a;
// daca avem copaci speciali facem m_a intre suma si numarul lor
	if (count)
		m_a = (double)sum / count;
	else
		xmin_par = 0;
	if (xmin_par == 1000000)
		xmin_par = -1;
	printf("%ld\n", sum);
	printf("%.7lf\n", m_a);
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);

	return 0;
}
