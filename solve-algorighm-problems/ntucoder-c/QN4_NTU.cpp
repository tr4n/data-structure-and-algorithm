#include<iostream>
#define _p(i,j) i*m + j
using namespace std; 
int a[1003][1003];
int N, M, T; 

int X[]= {1,0,-1,0};
int Y[]= {0,1,0,-1};
inline int Sub(int a, int b)
{
	if(a > b) return 1; 
	else return 0;
}

void floodfill(int x , int y)
{
	if(a[x][y] == 0)
		return ; 
	else
	 a[x][y] = 0; 
	 
	
	for(int i = 0 ;i < 4 ;i ++)
	{
		if(	x +X[i]     >= 1 && x + X[i]  <= N 
			&& y + Y[i] >= 1 && y + Y[i] <= M )
			floodfill(x+X[i], y + Y[i]);
	}
	
}


main()
{
	freopen("inQN4.txt","r",stdin);
	
	cin>> N >> M; 
	int A[N+3][M+3];
	
	for(int i =1 ;i <= N ;i ++)
	{
		for(int j =1 ;j <= M ;j ++)
		{
			cin >> A[i][j];
			
		}
	}
	
	cin >> T ; 
	while(T--)
	{
		int h,cnt = 0; 
		cin >> h; 
		
	
		
		
		for(int i =1 ;i <= N ;i ++)
		{
			for(int j =1 ;j <= M ;j ++)
			{
				a[i][j] = Sub(A[i][j], h);
				
			}
		}
		
		for(int i =1 ;i <= N ;i ++)
			for(int j =1 ;j <= M ;j ++)
			{
				if(a[i][j] == 1)
				{
					cnt ++ ; 
					floodfill(i,j);
				}
			}
		
		cout << cnt << " ";
	}
	
}
