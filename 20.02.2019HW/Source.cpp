#include <iostream>
#include <windows.h>
#include<iomanip>
#include<locale.h>

using namespace std;

void FillArray(int *p, int n)
{

	for (int i = 0; i < n; i++)
	{
		p[i] = 0 + rand() % 100;
	}
}

void PrintArray(int *p, int n)
{

	for (size_t i = 0; i < n; i++)
	{

		cout << p[i] << " ";


	}
	cout << endl;
}

void Sort(int a[], int n)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			if (a[j] > a[j-1])
			{
				swap(a[j], a[j - 1]);
			}

		}

	}

}

int Binary(int a[], int high, int x,int low=0)
{

	int middle = (high + low) / 2;;

	if (a[middle] == x)
	{
		return middle;
	}

	if (a[middle] < x)
	{
		middle = Binary(a, middle, x);
	}
	else if (a[middle] > x)
	{
		middle = Binary(a, high, x, middle);
	}

	return middle;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int flag;
	const int n = 10;
	int A[n], x;

	do
	{
		FillArray(A, n);
		PrintArray(A, n);
		Sort(A, n);
		PrintArray(A, n);
		cout << "Chislo?";
		cin >> x ;

		cout << Binary(A, n, x) << endl;

		cout << "Continue?1/0";
		cin >> flag;

	} while (flag == 1);

}