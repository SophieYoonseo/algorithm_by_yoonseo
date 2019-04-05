#include <iostream>

#ifndef __BUBBLESORT_CPP
#define __BUBBLESORT_CPP

using namespace std;
int count(0);

void bubbleSort(int A[], int n)
{
	int temp;
	bool sorted;
	for(int i=0; i<n; i++)
	{
		sorted = true;
		for(int j=0; j<n-i-1; j++)
		{
			if(A[j+1]<A[j])
			{
				swap(A[j], A[j+1]);
				count++;
				sorted = false;
			}	
		}
		if(sorted==true) return;
	}
}

int main()
{
	int size;
	cin >> size;
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];
		
	bubbleSort(A, size);
	cout << count << endl;
		
	
}

#endif
