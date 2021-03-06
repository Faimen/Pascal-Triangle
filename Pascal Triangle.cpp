// Pascal Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

long factorial(int numb)
{
	long result = 1;
	for (int i = 1; i <= numb; i++)
	{
		result *= i;
	}
	return result;
}

long FactorialRecursion(int numb)
{
	if ((numb == 0)||(numb == 1))
	{
		return 1;
	}
	return numb * FactorialRecursion(numb - 1);
}


void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void qsort(int *arr, int b, int e)
{
	int l = b, r = e;
	int piv = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < piv)
			l++;
		while (arr[r] > piv)
			r--;
		if (l <= r)
			swap(&arr[l++], &arr[r--]);
	}
	if (b < r)
		qsort(arr, b, r);
	if (e > l)
		qsort(arr, l, e);
}  


int main()
{
	
	int arrTriangle[10];
	int n = sizeof(arrTriangle) / sizeof(int);
	//printf("%d\n", n);
	//printf("Input values(10) for array: ");
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		
		arrTriangle[i] = rand() % 255;
		//scanf("%d", &arrTriangle[i]);
	}
	printf("NON-sort array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%3d ", arrTriangle[i]);
	}
	printf("\n    SORT-array: ");
	qsort(arrTriangle, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%3d ", arrTriangle[i]);
	}
	printf("\n");
	int min, max, medium;
	min = arrTriangle[0];
	max = arrTriangle[9];
	medium = arrTriangle[n / 2];

	printf("min = %d, max = %d, mediana = %d\n", min, max, medium);
	
	
////Pascal Triangle///////////////////////////////////////////////////////////////////////////////////
	int numb;
	printf("Input number: ");
	scanf("%d", &numb);

	for (int i = 1; i <= numb; i++)
	{
		for (int a = numb; a >= i; a--)
		{
			printf("    ");//Tabulation
		}
		for (int j = 1; j <= i; j++)
		{
			printf("%3ld ", factorial(j));//Simple realization
		}
		for (int j = i-1; j >= 1; j--)
		{
			printf("%3ld ", FactorialRecursion(j)); //Recursion
		}
		printf("\n");
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}

