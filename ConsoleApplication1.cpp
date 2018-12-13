#include "pch.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;

//sortowanie quicksort
void quicksort(int liczba[], int lewy, int prawy)
{
	int v = liczba[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (liczba[i] < v) i++;
		while (liczba[j] > v) j--;
		if (i <= j)
		{
			x = liczba[i];
			liczba[i] = liczba[j];
			liczba[j] = x;
			i++; j--;
		}
	} while (i <= j);
	if (j > lewy) quicksort(liczba, lewy, j);
	if (i < prawy) quicksort(liczba, i, prawy);
}

int main()
{
	//tworzę tablicę z wprowadzeniem 15 liczb
	int liczba[15];
	int numer_kolumny = 0;

	cout << "Podaj 15 liczb:";
	do
	{
		cin >> liczba[numer_kolumny];
		numer_kolumny++;
	} while (numer_kolumny < 15);

	//szukam najmnijszego elementu
	int min;
	min = liczba[0];
	for (int i = 1; i < 15; i++)
	{
		if (min > liczba[i])
		{
			min = liczba[i];
		}
	}
	cout << "Najmniejszy element w tablicy to " << min << endl;

	//szukam największego elementu
	int max;
	max = liczba[0];
	for (int j = 1; j < 15; j++)
	{
		if (max < liczba[j])
		{
			max = liczba[j];
		}
	}
	cout << "Najwiekszy element w tablicy to " << max << endl;

	//licze średnią arytmetyczna elementów w tablicy
	int suma = 0;
	int k;
	for (k = 0; k < 15; k++) {
		suma += liczba[k];
	}
	float srednia_ar;
	srednia_ar = suma / 15;
	cout << "Srednia arytmetyczna elementow tablicy to:" << srednia_ar << endl;

	//licze średnią geometryczną elementów w tablicy
	int iloczyn = 1;
	int n;
	for (n = 0; n < 15; n++) {
		iloczyn *= liczba[n];
	}
	double srednia_geo;
	srednia_geo = pow(iloczyn, (1 / 15.00));
	cout << "Srednia geometryczna elementow tablicy to:" << srednia_geo << endl;

	//sortowanie bąbelkowe i mediana

	int sortbabelkowe, schowek;
	do
	{
		sortbabelkowe = 0;
		for (int p = 0; p < 14; p++)
		{
			if (liczba[p] > liczba[p + 1])
			{
				sortbabelkowe = sortbabelkowe + 1;
				schowek = liczba[p];
				liczba[p] = liczba[p + 1];
				liczba[p + 1] = schowek;
			}
		}
	} while (sortbabelkowe != 0);

	int r = 0;							//mediana
	cout << "Mediana z naszej tablicy to: " << liczba[r = 7] << "" << endl; // mediana
	cout << "Sortowanie babelkowe" << endl;
	for (int u = 0; u < 15; u++)
	{
		cout << liczba[u] << " ";
	}
	cout << endl;
	
	cout << "Sortowanie quicksort" << endl;
	quicksort(liczba,0, 14);
	for (int u = 0; u < 15; u++)
	{
		cout << liczba[u] << " ";
	}
	cout << endl;
}
	


