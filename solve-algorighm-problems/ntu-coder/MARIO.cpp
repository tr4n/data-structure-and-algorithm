#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>


#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define MAX (int)5e5
#define MAX_INT 1e9
#define _p(i,j) (i-1)*m + j



using namespace std;

typedef pair <int, int> ii; 


int  V, E, n = 3, m = 4; 


vector <ii> A[MAX];
int d[MAX];
int Trace[MAX];

void InitGraph()
{
	
	cin >> n >> m ; 
	
	V = n*m; 
	E = n*(m-1) + (n-1)*m;
	
	memset(Trace, -1, sizeof(int));
	for(int i =1 ;i <= n ;i ++)
	{
		for(int j =1 ;j <= m-1 ;j ++ )
		{
			int a; 
			cin >> a; 
			
			A[_p(i,j)].push_back(ii(a,_p(i,j+1)));
			A[_p(i,j+1)].push_back(ii(a,_p(i,j)));
			
		}
	}
	
	for(int i =1 ;i <= n-1 ;i ++)
	{
		for(int j =1 ;j <= m ;j ++)
		{
			int w ; 
			cin >> w; 
			A[_p(i,j)]  .push_back( ii (w, _p(i+1,j) ));
			A[_p(i+1,j)].push_back( ii (w, _p(i  ,j) ));
			
			
		}
	}
	
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
	//	for( ii e: A[u])
		{
		//	int  v = .second;
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
		trace(Trace[k]);
	}
}



main()
{
	freopen("inMARIO.txt","r",stdin);
	
	
	InitGraph();
	
	cout << Dijkstra(1,V)<< endl;
	
	trace(V);
	

	
}
