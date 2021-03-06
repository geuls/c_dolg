#include <stdio.h>
#include <stdlib.h> /* позволяет включить функцию calloc*/
#include "stdafx.h"
int function(int n, int *a, int *b)
{
	return (n == 0) ? 0 : a[0] * b[0] + function(n - 1, a + 1, b + 1); /* тернарный оператор, который
																	   зависит от введенного значения n*/
}

int main(int argc, char *argv[])
{
	int i, n, *A, *a, *B, *b;
	printf("n=");
	scanf_s("%d", &n);

	A = (int*)calloc(n, sizeof(int)); 
	B = (int*)calloc(n, sizeof(int));

	a = A;
	b = B;

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &b[i]);
	}

	printf("%d\n", function(n, a, b));

	free(A); /* освобождает блок памяти, выделенный под массив А, аналогично для строки 33 и массива В*/
	free(B);
	
	return 0;
}