#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>


#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define MAX 1998
#define MAX_INT 1e9

using namespace std;

typedef pair <int, int> ii; 

vector <ii> A[MAX];



int n, m, G, E; 




int Dijkstra(int Start, int Target)
{
	
	priority_queue< ii, vector <ii>, greater <ii> > pq; 
	
	for(int i =1 ;i <= G ;i ++) d[i] = MAX_INT; 
	d[Start] = 0; 
	
	pq.push_back(ii(0,Start));
	
	while(pq.size())
	{
		
		int du = pq.top().second; 
		int  u = pq.top().first;
		
		if(u == Target) return du; 
		if(du != d[u]) continue; 
		
		pq.pop();
		
		for(int i = 0 ;v = A[u][i].second ;i ++)
		{
			int uv = A[u][i].first;		
			
			if(d[v] > du + uv)
			{
				d[v] = du + uv;
				pq.push(ii(d[v], v));
			}
						
		}
		
	}	
}





main()
{
	freopen("inBUS2.txt","r",stdin);
	
	int N, M; 
	cin >> N >> M ; 
	
	int A[N+3][M+3];
	int F[N+3][M+3];
	
	For(i,1,N)
	{
		For(j,1,M)
		{
			cin >> A[i][j];
			
			if(A[i][j] == 1)
				A[i][j] = 0;
			else 
				A[i][j] = 1; 
		}
	}
	// Print Check
	
	For(i,1,N)
	{
		For(j,1,M) cout << A[i][j] << " ";
		cout << endl;
	}
	
	cout << " ___" << endl;
	
	
	
	
	//
	F[0][0] = F[0][1] = F[1][0] = 0;
	A[0][1] = A[1][0] = 0;
	
	For(i,1,N) F[i][1] = A[i-1][1] + F[i-1][1]+1;
	For(i,1,M) F[1][i] = A[1][i-1] + F[1][i-1]+1;
	
	For(i,2,N)
	{
		For(j,2,M)
		{
			int A10 = A[i-1][j] , A01 = A[i][j-1];
			
			F[i][j] = 1+min(F[i-1][j] + A[i-1][j], F[i][j-1] + A[i][j-1]);
			
		
		}
	}
	
	//
	
	For(i,1,N)
	{
		For(j,1,M) cout << F[i][j] << " ";
		cout << endl;
	}
	
	cout << " ___" << endl;
	
	
	cout << F[N][M]  << endl;
}
