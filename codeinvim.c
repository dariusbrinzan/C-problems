#include <stdio.h>

#define NMAX 101

// functie pentru sortarea descrescatoare a vectorului
void bubble_sort(int n, int x[NMAX])
{   for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (x[i] < x[j]) {
				int tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}
}

int main(void)
{	int n, grade_array[NMAX], credits, pos_cred[NMAX], credit_goal;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &grade_array[i]);

	int sum = 0, k = -1;
// efectuez suma de credite si adaug elementele diferite de 10 intr-un vector
	for (int i = 0; i < n; ++i) {
		scanf("%d", &credits);

		sum = sum + (grade_array[i] * credits);

		if (grade_array[i] != 10)
			pos_cred[++k] = (10 - grade_array[i]) * credits;
	}
// citesc goal-ul peste care trebuie sa trec
	scanf("%d", &credit_goal);
// am sortat vectorul de potentiale credite descrescator
	bubble_sort(k, pos_cred);
	int ok = 1, count = 0;
// daca suma creditelor este mai mica decat goal-ul la care vreau sa ajung
// adaug primul element din vectorul sortat descrescator
	for (int i = 0; i <= k && ok == 1; ++i) {
		if (sum + pos_cred[i] < credit_goal)
			sum = sum + pos_cred[i];
	    else
			ok = 0;
// numar operatiile
		++count;
	}
	if (ok == 0) {
// afisez numarul de operatii
		printf("%d\n", count);
	} else {
		printf("-1\n");
	}
	return 0;
}
