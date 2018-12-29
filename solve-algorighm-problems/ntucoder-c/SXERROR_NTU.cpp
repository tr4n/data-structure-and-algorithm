#include<iostream>
using namespace std; 

main()
{
	int N; 
	cin >> N; 
	int A[N+3];
	for(int i =1 ;i <= N ;i ++)
	{
		cin >> A[i];
	}
	/*
	for(int i = 1 ;i <= N-1 ;i ++)
	
	{
		for(int j =i ;j <= N-1 ;j ++)
		{
			if(A[j]> A[j+1])
				swap(A[j],A[j+1]);
		}
	}
	
	for(int i =1 ;i <= N ;i ++)
	{
		cout << A[i] << " ";
	}
	*/
	
	if(N <= 2)
	{
		cout << -1 << endl;
	}
	else 
	{
		for(int i = N ;i >= 1 ;i --)
			cout << i << " ";
		
	}
	
	
}
