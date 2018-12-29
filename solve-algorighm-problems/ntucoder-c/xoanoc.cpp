#include<iostream>
#include<cstdio>

using namespace std;

main()
{
	
	int N; 
	cin >> N; 
	int A[N+3][N+3];
	int cnt = 0,Sum = 0;
	int p = 1, n = N ; 
	
	while(p<= n)
	{
		
		for(int i =p ;i <= n ;i ++)
		{
			A[p][i] = ++ cnt;
		}
		
		for(int i = p+1 ;i <= n ; i++)
		{
			A[i][n] = ++ cnt;
		}
		for(int i = n-1;i >= p ;i --)
		{
			A[n][i] = ++ cnt;
		}
		for(int i = n-1 ;i >= p+1; i--)
		{
			A[i][p] = ++cnt;
		}
		
		n--;p++;
		
	}
	
	for(int i =1 ;i <= N ;i ++)
	{
		for(int j =1 ;j <= N ;j ++) 
		{
			if(A[i][j]  < 10) cout << "  ";
			else if(A[i][j] < 100) cout << " ";
			
			
			cout << A[i][j] << " ";
			Sum+= A[i][j] ; 
		}
		cout << endl;
	}
	
}
