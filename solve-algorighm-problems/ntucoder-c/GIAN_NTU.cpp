#include<iostream>

using namespace std; 


main()
{
	int N,M; 
	cin >> M >> N; 
	
	int A[M+3][N+3];
	
	for(int i =1 ;i <= M ;i ++)
	{
		for(int j = 1 ;j <= N ;j ++)
		{
			cin >> A[i][j];
		}
	}
	
	int F[M+3][N+3];
	F[1][1] = A[1][1];
	for(int i = 0 ;i <= M ;i ++)
		F[i][0] = 0; 
	for(int i = 0; i<= N ;i ++)
		F[0][i] = 0;
	
	for(int i =1 ;i <= M ;i ++)
	{
		for(int j =1 ;j <= N ;j ++)
		{
			F[i][j] = A[i][j] + max(F[i-1][j],F[i][j-1] );
		}
		
	}
	
	cout << F[M][N];
}
