#include<iostream>
#include<algorithm>
#include<stack>
using namespace std; 

typedef pair <int,int> ii; 
int N,M; 
int Answer = 0 ; 
int A[100][100];
int F[100][100];

stack<ii> Trace; 


main()
{
	freopen("inDirection.txt","r",stdin);
	cin >> M >> N; 
	for(int i =1 ;i <= M ;i ++)
	{
		for(int j =1 ;j <= N ;j++)
		{
			cin >> A[i][j] ; 
		}
	}
	
	for(int i = 0 ;i <= max(M,N) ;i ++)
	{
		F[i][0] = F[0][i] = 0; 
	}
	
	for(int i = 1 ;i <= M ;i ++)
	{
		for(int j = 1;j <= N ;j ++)
		{
			F[i][j] = A[i][j] + max(F[i-1][j] , F[i][j-1]);
		}
	}
	cout << "Answer : " << F[M][N] << endl;
	int i = M, j = N; 
	while(i*j )
	{
		Trace.push(ii(i,j));
		if(F[i][j] == A[i][j] +F[i-1][j])		
			i--;		
		else
			j--;	
	}
	
	while(Trace.size())
	{
		cout << "( " << Trace.top().first << " , " << Trace.top().second  << " ) "<< endl;
		Trace.pop();
	}
	
	
}
