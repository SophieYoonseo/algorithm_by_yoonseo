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
		max=0; // �ʱⰪ  
		for(int j=0; j<= i; j++)
		{
			if(A[max]<A[j])
			{
				max=j;
				count++; // ��Ƚ���� �������� 
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
	int size; //������ �迭 ũ�� 
	cout << "�Է��ϰ��� �ϴ� �迭�� ũ�⸦ �Է��ϼ���.";
	cin >> size;
	int A[size]; // ������ �迭 
	
	cout << "���������� �Է��ϼ���.";
	for(int i=0; i<size; i++)
	{
		cin >> A[i];
	}
	selectionSort(A, size); 
	cout << "�� �� Ƚ����? " << count << endl;
	
}



#endif

	


