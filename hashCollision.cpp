#include <iostream>
#include <cstdlib>

using namespace std;

int count;

int hashFunc(const int H[], bool fully[], int index, int M)
{
	int i = (index + 1) % M;
    if(fully[i] == true) return i;
    else{
        count++;
        return hashFunc(H, fully, i, M);
    }	
}

int primeNumber(int n)
{
	for(int i = 2; i < n/2; i++)
            if((n%i)==0) return primeNumber(n+1);
    return n;
}

int main()
{
	int N, element, index; // N : SIZE
	cin>>N;
   	int M = primeNumber(N*2);
   	
	int H[M];
	bool fully[M];
	
	for(int i=0; i<M; i++)
		fully[i]=true;
		
	for(int i=0; i<N; i++)
	{
		cin>>element;
		index=element%M;
		if(fully[index]==true)
		{
			H[index] = element;
			fully[index] = false;
		}
		else 
		{
			count++;
			index = hashFunc(H, fully, index, M);
			H[index]=element;
			fully[index] = false;
		}
	}
	cout << count << endl;
}
