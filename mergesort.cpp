#include <iostream>

#ifndef __MERGESORT_CPP
#define __MERGESORT_CPP

using namespace std;

int count(0);

void merge(int A[], int left, int mid, int right)
{
	
	int first=left;
	int middle=mid+1;
	int last=1;
	int temp[right-left+1];
	
	while(first<=mid && middle<=right)
	{
		if(A[first]<A[middle])
		{
			temp[last++] = A[first++];
			count++;	
		}		
			else
			{
				temp[last++] = A[middle++];
				count++;
			}
			
	}
	while(first<=mid)
	{
		temp[last++] = A[first++];
	}
	while(middle<=right)
	{
		temp[last++] = A[middle++];
	}
	
	first=left;
	last=1;
	
	while(first<=right)
	{
		A[first++]=temp[last++];
	}
}

void mergeSort(int A[], int left, int right)
{
   int mid;

   if(left < right)
   {
      // �߰� ������ ����Ѵ�.
      mid = (left+right) / 2;

      // �ѷ� ������ ������ �����Ѵ�.
      mergeSort(A, left, mid);
      mergeSort(A, mid+1, right);

      // ���ĵ� �� �迭�� �����Ѵ�.
      merge(A, left, mid, right);
   }
}

int main()
{
	int size;
	cin >> size;
	int A[size];
	for(int i=0; i<size; i++)
		cin >> A[i];
		
	mergeSort(A, 0, size-1);
	cout << count << endl;
}

#endif
