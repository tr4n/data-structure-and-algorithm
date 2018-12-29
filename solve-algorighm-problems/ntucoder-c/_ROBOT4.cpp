#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>


#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define MAX (int)403
#define MAX_INT 10000
#define _p(i,j) (i-1)*m + j



using namespace std;

typedef pair <int, int> ii; 

int Dx[] = {0, 0,1,0,-1};
int Dy[] = {0, 1,0,-1,0};


int  V, E, n = 3, m = 4; 


int Target = 3, Start = 1;
ii Trace[MAX][MAX];
int Dir = 1;
bool Free[MAX][MAX];

int A[500];

ii Vector(int a, int b)
{
	int x = (b-a) %m ;
	int y = (int) ((b-a-x)/m);
	
	return ii(y,x);
}

int Direct(int c, int a, int b)
{
	ii Vector1 = Vector(c, a);
	ii Vector2 = Vector(a, b);
	
		
	int X1 = Vector1.first;
	int Y1 = Vector1.second;
	int X2 = Vector2.first;
	int Y2 = Vector2.second;
	
	if( (X1 == 0 && Y1 ==0) 
	 || (X2 ==0  && Y2 == 0) 
	 || (X2 != 0 && Y2 != 0)) 
	  return -1;
	
	// -1 : Wrong; 1 : Left  , 2 : Up, 3 : Right ; 4 : Down
	if(X1 ==0) // Y1 != 0
	{
		if(Y1 >  0)
		{
			if(X2 == 0 && Y2 > 0 ) return 3; 
			if(X2 <  0 && Y2 == 0) return 2; 
			
		}
		else
		{
			if(X2 == 0 && Y2 < 0) return 1;
			if(X2 >  0 && Y2== 0) return 4;
		}
	}
	else // X1 != 0 , Y1 ==0
	{
		if(X1 > 0)
		{
			if(X2 ==0 && Y2 >  0) return 3;
			if(X2 > 0 && Y2 == 0) return 4;
		}
		else
		{
			if(X2 ==0 && Y2 < 0) return 1;
			if(X2 < 0 && Y2 ==0) return 2;
		}
		
	}
	
}



void InitGraph()
{
	cin >> n >> m ;
	
	for(int i =1 ;i <= n ;i ++)
	{
		for(int j =1 ;j <= m ;j ++)
		{
			
			cin >> A[_p(i,j)];					
			
		}
	}
	 
	int xd, yd; 
	cin >> xd >> yd;
	
	Target = _p(xd,yd);
	
	V = n*m; 
	E = n*(m-1) + (n-1)*m;
	
	
	
	for(int i =1 ;i <= V ;i ++) 
		for(int j =1 ;j <= V ;j ++)
			{
				if(i!= j) Free[i][j] = true;
				else Free[i][j] = false;
			}
	
	
	
	
	
}




void trace(int k )
{
	cout << k << " " ; 
	if(!Trace[k].empty())
	{
		int v = Trace[k].back();
		Trace[k].pop_back();
		
		trace(v);
		
	}
}

bool Check(int u,int i)
{
	
		int k = Dx[i]*m + Dy[i] ;
	if(u%m ==0 && k ==1	)	 return false;
	if(u%m ==1 && k ==-1)	 return false;
	if(u<=m    && k == -m)	 return false;
	if(u > (n-1)*m && k == m)return false;
	
//	return Free[u+k];
	return Free[u][u+k];	
}


void Result()
{
	cout << " Found" << endl;
}

void Visit(int u, int dir)
{
	int a = Start; 
	
	//cout << u << " ";
	if(u == Target) 
	{
		Result();
		return;	
	} 
	
	if(u != Start) 
		  a=Trace[u][dir].first;

	Free[a][u] = false ; 
	 
	for(int i = 1 ;i <= 4 ;i ++)
	{
		if(Check(u,i))
		{
			int b = u + Dx[i]*m + Dy[i];
			if(u != Start)
			{
				 Dir = Direct(a,u,b);
				if(A[b]!= 1 && Dir!=1  )
				{
					Trace[b][Dir] = ii(u,Dir);
					Visit(b,Dir);
				}
			}
			else
			{
				if(b == 2  ) Dir = 3;
				if(b == m+1) Dir = 4;
				if(A[b] != 1)
				{
					Trace[b][Dir] = ii(1,0);
					Visit(b);
				}
			}
						
			
		}
		
	}
	 
	 	
	

	
}


main()
{
	freopen("_inROBOT4.txt","r",stdin);
	InitGraph();
	
	for(int i =1 ;i <= V ;i ++)
	{
		cout << A[i] << " ";
		if(i%m ==0) cout << endl;
	}
	cout << endl;
	
	
	
	cout << Start << " " << Target << endl;
	
	Visit(1);
	
	cout << endl;
	
//	trace(Target);
	
	for(int i =1 ;i <= V ;i ++)
	{
		cout << i << " : " ; 
		while(!Trace[i].empty())
		{
			cout << Trace[i].back() << " ";
			Trace[i].pop_back();
		}
		cout << endl;
	}


	
	

	

	
}
