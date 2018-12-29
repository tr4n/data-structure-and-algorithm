#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>

#define MAX (int)(1e5+3)
#define Number(i) (i-1)*((int)(u/i)+1)
using namespace std;

int N,cnt = 0;
priority_queue <int, vector<int>, greater<int> > pq;

int Free[MAX];

void Visit(int u)
{
	
	
	if(u==0) return; 
	 cnt ++; 
	 
	 if(u!= N && !Free[u]) pq.push(u);
	 Free[u] = 1 ; 
	 
	 	
	int Sqrt = sqrt(u),k = 0;
	for(int i = 1 ;i <= Sqrt ; i++ )
	{
		if(u%i==0) 		
		{
			int v = Number(i);	
					
				if(Free[v]==0)
				Visit(v);
			
		}
	}

	
}


main()
{
//	freopen("ZeroPath.txt","r",stdin);
	cin >> N; 
	Visit(N);	
	memset(Free,0,sizeof(int));
	
	pq.push(0);
	cout << pq.size() << endl;
		
	int k = -1;
	
	for(int i =1 ;i <= cnt ;i ++)
	{
		if(k != pq.top())
		{
			cout << pq.top() <<  " ";
			k = pq.top();
			
				
		}
		pq.pop();
		
	}
	

	
	
	
}

