#include <stdio.h>
#include <stdlib.h>

int n;
double** A;
double* b;
double* x;

int main(int argc, char* argv[])
{
	// Iteratory pętli
	int i, j;

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

	// Zaalokowanie wektora x
	x = (double*) malloc(n * sizeof(double));

	// Wczytanie macierzy A wierszami
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%lf ", &A[i][j]);

	// Wczytanie wektora b
	for(i = 0; i < n; i++)
			scanf("%lf", &b[i]);

	double suma;
	x[n - 1] = b[n - 1] / A[n - 1][n - 1];
	for(i = n - 2; i >= 0; i--)
	{
		suma = 0;
		for(j = i + 1; j < n; j++)
			suma += x[j] * A[i][j];
		x[i] = (b[i] - suma) / A[i][i];
	}

	// Wypisanie wyniku
	for(i = 0; i < n; i++)
		printf("%0.6f\n", x[i]);
	
	return 0;
}

