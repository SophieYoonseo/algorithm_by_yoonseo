#include <iostream>

#ifndef __COUNTINGSORT_CPP
#define __COUNTINGSORT_CPP

using namespace std;

void countingSort(int A[], int n)
{
	int max=A[0];
	int min=A[0];
	for(int i=0; i<n; i++)
	{
		if(A[i]>max)
		{
			max=A[i];	
		} 
		if(A[i]<min) 
		{
			min=A[i];	
		}
	}
	
	int k=max-min+1;
	int C[k];
	
	for(int i=0; i<k; i++)
	{
		C[i]=0;
	}
	for(int j=0; j<n; j++)
	{
		C[A[j]-min]++;
	}
	for(int i=1; i<k; i++)
	{
		C[i]=C[i]+C[i-1];
	}
	for(int i=0; i<k; i++)
	{
		cout << C[i] << " ";
	}
	
}
int main()
{
	int size;
	cin >> size;
	int A[size];
	
	for(int i = 0; i < size; i++)
	{
		cin >> A[i];
	} 
	countingSort(A, size);

	return 0;
}

#endif

