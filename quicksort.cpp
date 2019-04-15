#include <iostream>

#ifndef __QUICKSORT_CPP
#define __QUICKSORT_CPP

using namespace std;

int count(0);

int partition(int A[], int p, int r)
{
	int x=A[r];
	int i=p-1;
	for(int j=p; j<=r-1; j++)
	{
		if(A[j]<=x)
		{
			swap(A[++i], A[j]);
			//A[++i] = A[j];
			count++;
		}
	}
	swap(A[i+1], A[r]);
	count++;
	return i+1;
}

void quickSort(int A[], int p, int r)
{
	int q=0;
	if(p<r)
	{
		q=partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

int main()
{
	int size;
	cin >> size;
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];
		
	quickSort(A, 0, size-1);
	cout << count << endl;
	
	return 0;
}
#endif
