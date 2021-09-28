#include <stdio.h>

#define NMAX 100
#define nmax 10

int sort_cresc_descr(int x)
{   int nr_cresc = 0, nr_desc = 0, k = -1, count, v[nmax];
// introduc cifrele numarului intr-un vector
	while (x > 0) {
		v[++k] = x % 10;
		x /= 10;
	}
// sortez vectorul obtinut
	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			if (v[i] > v[j]) {
				int tmp;
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
// pentru cand sortez crescator si am o cifra egala cu 0 o elimin
	count = 0;
	while (v[count] == 0 && count < k)
		++count;
// formez numarul crescator si plec de unde dispare prima cifra 0
	for (int i = count; i <= k; ++i)
		nr_cresc = nr_cresc * 10 + v[i];
// formez numarul descrescator
	for (int i = k; i > -1; --i)
		nr_desc = nr_desc * 10 + v[i];
// returnez diferenta dintre cele 2 numere obtinute
	return nr_desc - nr_cresc;
}

int main(void)
{	int n, w[NMAX];
	int l = -1;
// citesc numarul
	scanf("%d", &n);
// introduc pe prima pozitie prima diferenta
	w[++l] = sort_cresc_descr(n);
// initializez ok = -1
	int ok = -1;
	while (ok == -1) {
		++l;
// apelez functia pe pozitia curenta
		w[l] = sort_cresc_descr(w[l - 1]);
// verific daca numarul se gaseste in vector
		for (int i = l - 1; i > -1; --i) {
			if (w[l] == w[i])
				ok = i;
		}
	}
	printf("%d\n", ok);
	for (int i = ok; i < l; ++i)
		printf("%d ", w[i]);

	return 0;
}
