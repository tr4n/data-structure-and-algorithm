#include<iostream>
using namespace std; 

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};
int A[1003][1003], ;
void floodfill(int x, int y)
{
	
	
	if(A[x][y] != 1)
		return; 
	
	
	if(cnt <= 1)
	{
		A[x][y] = 2;
	}
	
	for(int i = )
	
	
}


bool Check(int x, int y)
{
	
}
main()
{
	int N, M,K,T; 
	
	cin >> T; 
	while(T--)
	{
		cin >> N >> M >> K; 
		int A[N+3][M+3];
		
		for(int i =1 ;i <= N ;i ++)
		{
			for(int j =1 ;j <= M ;j ++)
				cin A[i][j]; 
		}
		
		for(int i =1 ;i <= N ;i ++)
		{
			for(int j =1 ;j <= M ;j ++)
			{
				if(A[i][j] == 1)
				{
					int cnt = 0;
					for(int i = 0 ;i <4 ;i ++)
					{
						if(x + X[i] >= 1 && x + X[i] <= N && y + Y[i] >= 1 && y + Y[i] <= M)
						if(A[x+X[i]][y + Y[i]] != 1)
						cnt ++;
					}
					
					if(cnt == 1)
					{
						
					}
					
				}
			}
		}
	}
	
	
}
