#include <iostream>

#ifndef __RADIXSORT_CPP
#define __RADIXSORT_CPP

using namespace std;

void radixSort(int A[], int size, int k){
  
  	int temp[size];
  	int digit = 1;

  	for(int j=0; j<k; j++){
    	int bucket[10] = { 0 };
    
    	for (int i = 0; i < size; i++)
      		bucket[(A[i] / digit) % 10]++;
    
    	for (int i = 1; i < 10; i++)
      		bucket[i] += bucket[i - 1];
    
    	for (int i = size - 1; i >= 0; i--)
      		temp[--bucket[(A[i] / digit) % 10]] = A[i];
    
    	for (int i = 0; i < size; i++)
      		A[i] = temp[i];
    
    	digit *= 10;
    
  	}
}

int main(){
  
  	int size;
  	int t;
  	cin >> size;
  	cin >> t;
  	int A[size];
  
  	for(int i=0; i<size; i++)
  	{
  		cin >> A[i];
  	}
 
  	radixSort(A, size, t);
  	
  	for(int i=0; i<size; i++)
  	{
  		cout << A[i] << " ";
  	}
  	

  	return 0;
}

#endif
