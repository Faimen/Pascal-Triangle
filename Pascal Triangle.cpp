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


int randMedium(int i)
{
	srand(time(NULL));
	int result = rand() % i;
	return  result;
}

int mediana(int *arr, int l,int k)
{
	if (sizeof(arr)*l/sizeof(arr[0]) == 1)
	{
		return arr[0];
	}

	int	Medium = randMedium(l);
	int *Lows = {}, *Highs = {}, *Mediums = {};
	int L = 1, H = 1, M = 1;
	for (int i = 0; i < sizeof(arr)*l / sizeof(arr[0]); i++)
	{
		if (arr[i] < arr[Medium])
		{
			
			Lows = (int*)realloc(Lows,(sizeof(Lows)*L / sizeof(Lows[0]) + 1) * sizeof(int));
			
			Lows[(sizeof(Lows)*L / sizeof(Lows[0])) - 1] = arr[i];
			L += 1;
		}
		if (arr[i] > arr[Medium])
		{
			Highs = (int*)realloc(Highs,(sizeof(Highs)*L / sizeof(Highs[0]) + 1) * sizeof(int));
			
			Highs[(sizeof(Highs)*H / sizeof(Highs[0])) - 1] = arr[i];
			H += 1;
		}
		if (arr[i] == arr[Medium])
		{
			Mediums = (int*)realloc(Mediums,(sizeof(Mediums)*L / sizeof(Mediums[0]) + 1) * sizeof(int));
			
			Mediums[(sizeof(Mediums)*M / sizeof(Mediums[0])) - 1] = arr[i];
			M += 1;
		}
	}

	if (k < (sizeof(Lows)*L / sizeof(Lows[0])))
	{
		return mediana(Lows, L, randMedium(L));
	}
	else if (k <(sizeof(Lows)*L / sizeof(Lows[0])) + (sizeof(Mediums)*M / sizeof(Mediums[0])))
	{
		return Mediums[0];
	}
	else
	{
		return mediana(Highs, H = (H - (sizeof(Lows)*L / sizeof(Lows[0])) - (sizeof(Mediums)*M / sizeof(Mediums[0]))), randMedium(H));
	}


}

int main()
{
	
	int arrTriangle[10];
	int n = sizeof(arrTriangle) / sizeof(int);
	printf("%d\n", n);
	printf("Input values(10) for array: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arrTriangle[i]);
	}
	int min = arrTriangle[0], max = arrTriangle[0], medium = arrTriangle[0];
	for (int i = 0; i < n; i++)
	{
		if (min > arrTriangle[i]) { min = arrTriangle[i]; }
		if (max < arrTriangle[i]) { max = arrTriangle[i]; }
	}
	printf("min = %d, max = %d\n", min, max);
	//Medium of array !Work
	/*int result = mediana(arrTriangle, n, randMedium(n));
	printf("%d   ", mediana(arrTriangle, n, randMedium(n))); */
	


	
	
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

