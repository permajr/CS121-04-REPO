#include <iostream>

using namespace std;
template <typename T>
void mergesort1(T* arrayptr, const int& arraysize);
template <typename T>
void sortmerge1(T* arrayptr, const int& arraySize, int l, int r);

int main()
{
	int newArr[10];

	for (int num = 9; num >= 0; num--)
	{
		num >> newArr[num];
		cout << num;
	}
}
	


template <typename T>
void mergesort1(T* arrayptr, const int& arraysize)
{
	sortmerge1(arrayptr, arraySize 0, arraySize - 1);
}


template <typename T>
void sortmerge1(T * arrayptr, const int& arraySize, int l, int r)
{
	int mid, i, j, k;
	if (l < r)
	{
		mid = (r + 1) / 2;
		sortmerge1(arrayptr, arraySize, l, mid);
		sortmerge1(arrayptr, arraySize, mid + 1, r);
		T* temp = mnew T[arraySize];
		for (i = mid + 1; i > l; i--)
			temp[i - 1] = arrayptr[i - 1];
		for (j = mid; j < r; j++)
			temp[r + mid - j] = arrayptr[j + 1];
		for (k = l; k <= r; k++)
			arrayptr[k] = (temp[i] < temp[j]) ? temp[i++] : temp[j--]

	}
		delete[] temp;
			temp = 0;
	}