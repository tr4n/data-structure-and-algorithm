#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>

#define getbit(a,k) ((a>>1)&k)
using namespace std; 

void RadixSort(long A[], int Begin, int End, int k)
{
	int i = Begin, j = End;
	while(i<j && k>= 0)
	{
		while(getbit(A[i],k) == 0) i++;
		while(getbit(A[j],k) == 1) j--;
		swap(A[i],A[j]);
		if(getbit(A[i],k) == 0) i++;
	}
	
	
	
	RadixSort(A,Begin,i,k-1);
	RadixSort(A,j+1,End,k-1);
}


main()
{
	int N; 
	cin >> N; 
	long A[N+3];
	
	for(int i =1 ;i <= N ;i ++) cin >> A[i];
	RadixSort(A,1,N,20);
	
	for(int i =1 ;i <= N ;i ++) cout << A[i] << " ";
	
}




