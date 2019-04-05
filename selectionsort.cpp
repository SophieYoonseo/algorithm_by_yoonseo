#include <iostream>

#ifndef __SELECTIONSORT_CPP
#define __SELECTIONSORT_CPP

using namespace std;

int count(0);

void selectionSort(int A[], int n)
{
	int max;
	for(int i=n-1; i>0; i--)
	{
		max=0; // 초기값  
		for(int j=0; j<= i; j++)
		{
			if(A[max]<A[j])
			{
				max=j;
				count++; // 비교횟수를 세기위함 
			}
		}
		swap(A[i], A[max]);
	}
	
}


int main()
{
	int size; 
	
	cin >> size;
	int A[size]; 
	
	
	for(int i=0; i<size; i++)
	{
		cin >> A[i];
	}
	selectionSort(A, size); 
	cout << count << endl;
	
}



#endif

	


