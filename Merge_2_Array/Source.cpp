#include<iostream>
using namespace std;

void input(int a[], int n)
{
	cout << " Array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void Sort(int a[], int a_length)
{
	for (int i = 0; i < a_length; i++)
	{
		for (int j = 0; j < a_length; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void Mix2Array(int array1[], int array2[], int arraymix[], int array1_length, int array2_length, int& arraymix_length)
{
	arraymix_length = array1_length + array2_length;

	for (int i = 0; i < array1_length; i++)
	{
		arraymix[i] = array1[i];
	}

	for (int i = array1_length; i < array1_length + array2_length; i++)
	{
		arraymix[i] = array2[i - array1_length];
	}

	Sort(arraymix, array1_length + array2_length);
}

void collect(int a[], int b[], int c[], int n, int m, int& k)
{
	int i = 0;
	int j = 0;

	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else // a[i] >= b[j]
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}

	for (; i < n; i++) 
	{
		c[k] = a[i];
		k++;
	}

	for (; j < m; i++)
	{
		c[k] = b[j];
		k++;
	}
}

void output(int a[], int n)
{
	cout << " Output: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = { 0, 2, 4, 6, 8 };
	int c[100];
	int n = 5;
	int m = 5;
	int k = 0;

	/*cin >> n >> m;*/

	/*input(a, n);
	input(b, m);*/
	
	//collect(a, b, c, n, m, k);
	
	Mix2Array(a, b, c, 5, 5, k);

	output(c, k);

	return 0;
}