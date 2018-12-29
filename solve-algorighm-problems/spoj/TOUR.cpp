#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 200003

using namespace std; 

int N, M; 
int  Parent[MAX];
bool Color[MAX];
vector <int> A[MAX]; 

void InitGraph()
{
	cin >> N ;
	
	int p,q; 
	for(int i =1 ;i <= N-1 ;i ++)
	{
		cin >> p >> q; 
		A[p].push_back(q);
		A[q].push_back(p);
	}
	
	for(int i =1 ;i <= N ;i ++) A[i].push_back(0);
	
	for(int i =1 ;i <= N ;i ++) Color[i] = 0;
	
	
	
}


void Visit(int u, int b)
{
	if(u == b) return ;
	
	for(int i = 0,v ;  v = A[u][i] ;i ++)
	{
	
		if(v != Parent[u])
		{
			Parent[v] = u;
			Visit(v,b);
		}
	
	}
}

void trace ( int u, int a)
{
	Color[u] = 1; 

	if(u == a || u == 0) return ; 
	trace(Parent[u],a);
}

main()
{
	freopen("inTOUR.txt","r",stdin);
	InitGraph();
	
	
	cin >> M; 
	for(int i =1 ;i <= M ;i ++)
	{
		int a,b;
		cin >> a >> b; 
		
		for(int i =1 ; i<= N ;i ++) Parent[i] = 0;
		Visit(a,b);
		trace(b,a);
//		cout << endl;
	
	}
	int cnt = 0;
	for(int i =1 ;i<= N ;i ++)
		if(Color[i]==0)
			cnt ++;
	
	cout << cnt ; 
	
	
}




