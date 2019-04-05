#include <iostream>

#ifndef __INSERTIONSORT_CPP
#define __INSERTIONSORT_CPP

using namespace std;
int count(0);

void insertionSort(int A[], int n)
{
	int i,j;
	for(i=1; i<n; i++)
	{
		int newItem=A[i];
		for(j=i-1; j>=0;j--)//(loc>=0 && newItem<A[loc])
		{
			if(newItem<A[j]){
				A[j+1]=A[j];
				count++;
			}
			else
				break;
		}
		A[j+1]=newItem;
		count++;
	}	
}

int main()
{
	int size;
	cin >> size;
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];
		
	insertionSort(A, size);
	cout << count << endl;
}
#endif 
