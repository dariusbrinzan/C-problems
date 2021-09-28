#include <stdio.h>

#define NMAX 100

// functie in care verific secventele de 1 de pe linie
int line(int j, int n, int mat[NMAX][NMAX], int restriction[2 * NMAX][NMAX + 1])
{	int count = 0, ind;
	int ok = 1;
	for (int i = 0 ; i < n; ++i) {
		if (mat[j][i] == 1) {
			ind = i, ++count;
			while (mat[j][ind] == 1 && ind < n)
				++ind;
			if (restriction[j][count] != ind - i)
				ok = 0;
			i = ind;
		}
	}
	if (ok == 1)
		return 1;
	return 0;
}

// functie in care verific secventele de 1 de pe coloane
int row(int j, int n, int mat[NMAX][NMAX], int restriction[2 * NMAX][NMAX + 1])
{   int count = 0, pos;
	int ok = 1;
	for (int i = 0; i < n; ++i) {
		if (mat[i][j] == 1) {
			pos = i, ++count;
			while (mat[pos][j] == 1 && pos < n)
				++pos;
			if (restriction[j + n][count] != pos - i)
				ok = 0;
			i = pos;
		}
	}
	if (ok == 1)
		return 1;
	return 0;
}

int main(void)
{   int T, n, m;
	int restriction[2 * NMAX][NMAX + 1], matrix[NMAX][NMAX];
// citesc numarul de puzzle-uri
	scanf("%d", &T);
	while (T > 0) {
// citesc dimensiunea matricei
		scanf("%d%d", &n, &m);
// ciesc restrictiile
		for (int i = 0; i < n + m; i++) {
			scanf("%d", &restriction[i][0]);
			for (int j = 1; j <= restriction[i][0]; j++)
				scanf("%d", &restriction[i][j]);
		}
// citesc matricea
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				scanf("%d", &matrix[i][j]);
		}

		int ok = 1;
// verific restrictiile de pe linie
		for (int i = 0; i < n; ++i)
			ok = line(i, m, matrix, restriction);
// verific restrictiile de pe coloana
		for (int j = 0; j < m && ok == 1; ++j)
			ok = row(j, n, matrix, restriction);
		if (ok == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
		T--;
	}
	return 0;
}
