#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>


#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define MAX (int)5e5
#define MAX_INT 10000
#define _p(i,j) (i-1)*m + j



using namespace std;

typedef pair <int, int> ii; 


int  V, E, n = 3, m = 4; 


vector <ii> A[MAX];
int d[MAX];
int Trace[MAX];
int a[25][25];

priority_queue<int, vector<int>, greater<int> > q; 

void InitGraph()
{
	cin >> n >> m ;
	
	for(int i =1 ;i <= n ;i ++)
	{
		for(int j =1 ;j <= m ;j ++)
		{
			int x; 
			cin >> x; 
			a[i][j] = x; 
			if(x==1)
			{
				int a = MAX_INT+3;
				if(j<m)	A[_p(i,j)	].push_back	(	ii(a,	_p(i  ,j+1)));
				if(j<m)	A[_p(i,j+1)	].push_back	(	ii(a,	_p(i  ,j  )));
				if(i<n)	A[_p(i,j)	].push_back	( 	ii(a,   _p(i+1,j  )));
				if(i<n) A[_p(i+1,j)	].push_back	( 	ii(a,   _p(i  ,j  )));
							
			}
			else
			{
				int a = 0;
				int b = MAX_INT;
				if(j<m)	A[_p(i,j)	].push_back	(	ii(a,	_p(i  ,j+1)));
				if(j<m)	A[_p(i,j+1)	].push_back	(	ii(a,	_p(i  ,j  )));
				if(i<n)	A[_p(i,j)	].push_back	( 	ii(a,   _p(i+1,j  )));
				if(i<n) A[_p(i+1,j)	].push_back	( 	ii(a,   _p(i  ,j  )));
				
			}
			
			
			
			
			
		}
	}
	 
	
	V = n*m; 
	E = n*(m-1) + (n-1)*m;
	
	memset(Trace, -1, sizeof(int));
	
	
	for(int i =1 ;i <= V ;i ++)
		A[i].push_back(ii (0, 0));
	
	
}



int Dijkstra(int Start, int Target)
{
	
	priority_queue< ii, vector <ii>, greater <ii> > pq; 
	
	for(int i =1 ;i <= V ;i ++) d[i] = MAX_INT; 
	d[Start] = 0; 
	
	pq.push(ii(0,Start));
	
	while(pq.size())
	{
		
		int  u = pq.top().second; 
		int  du = pq.top().first;
		pq.pop();
		if(u == Target) return du; 
		if(du != d[u]) continue; 
		
		
		
		for(int i = 0 ;int v = A[u][i].second ;i ++)
	
		{
	
			int uv = A[u][i].first;		
			
			if(d[v] > du + uv)
			{
				d[v] = du + uv;
				pq.push(ii(d[v], v));
				
				Trace[v] = u;
			}
						
		}
		
	}	
}



void trace(int k )
{
	if(Trace[k] != -1)
	{
		cout << k <<" ";
		q.push(k);
		trace(Trace[k]);
	}
}



main()
{
	freopen("inROBOT4.txt","r",stdin);
	
	
	InitGraph();
	
	int x, y; 
	cin >> x >> y; 
	
	
	
	cout << Dijkstra(1,_p(x,y))<< endl;
	
	trace(_p(x,y));
	cout << endl;
	
	for(int i =1 ;i <= n ;i ++)
	{
		for(int j =1 ;j<= m ;j ++)
		{
			if(i == j && i == 1)
			{
				cout << "H "; 
			}
			else if(i == x && j == y)
			{
				cout << "G ";
			}
			else
			{
				if(a[i][j]==0) cout << ". ";
				else cout << "o ";
			}
		}
		cout << endl;
	}
	
	cout << endl;
	
	for(int i =1 ;i<= n ;i ++)
	{
		for(int j =1 ;j <= m ;j ++)
		{
		 	
		 	
		 	if(_p(i,j) == q.top() )
			{
				if(_p(i,j) == 1) 
					cout << "H ";
				else
				if( _p(i,j)== _p(x,y))
					cout << "G ";
				else 
				cout << "*" << " ";
				q.pop();
			}
			else 
			{
				if(a[i][j]==0) cout << ". ";
				else cout << "o ";
			}
		}
		cout << endl;
	}
	

	
}
