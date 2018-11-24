#include <stdio.h>
#include <stdlib.h>

int n;
double** A;
double* b;

int main(int argc, char* argv[])
{
	// Iteratory pętli for
	int i, j, k;

	// Wczytanie wymiaru
	scanf("%d", &n);

	// Wymiar poza dopuszczalnym zakresem - wyjście
	if(!(n >= 3 && n <=10))
		return -1;

	// Zaalokowanie macierzy A
	A = (double**) malloc(n * sizeof(double*));
	for(i = 0; i < n; i++)
		A[i] = (double*) malloc(n * sizeof(double));

	// Zaalokowanie wektora b
	b = (double*) malloc(n * sizeof(double));

	// Wczytanie macierzy A wierszami
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%lf ", &A[i][j]);

	// Wczytanie wektora b
	for(i = 0; i < n; i++)
			scanf("%lf", &b[i]);

	// Przekształcenia
	double d;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			d = A[j][i] / A[i][i];
			for(k = i; k < n; k++)
				A[j][k] -= d * A[i][k];
			b[j] -= d * b[i];
		}
	}

	// Wypisanie wymiaru
	printf("%d\n", n);

	// Wypisanie macierzy A
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%0.6f ", A[i][j]);
		printf("\n");
	}

	// Wypisanie wektora b
	for(i = 0; i < n; i++)
		printf("%0.6f\n", b[i]);
	
	return 0;
}

