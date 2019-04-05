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
	for(int i=0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void swap(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int size; //정렬할 배열 크기 
	cout << "입력하고자 하는 배열의 크기를 입력하세요.";
	cin >> size;
	int A[size]; // 정렬할 배열 
	
	cout << "랜덤변수를 입력하세요.";
	for(int i=0; i<size; i++)
	{
		cin >> A[i];
	}
	selectionSort(A, size); 
	cout << "총 비교 횟수는? " << count << endl;
	
}



#endif

	


