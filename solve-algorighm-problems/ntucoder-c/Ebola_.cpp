#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>
#define MAX (int)(1e5+3)
 using namespace std; 
 
 vector <int> A[MAX];
 int Visited[MAX], Parent[MAX];
 
 priority_queue <int, vector<int>, greater<int> > pq; 
 
 int N, M, K, cnt=0 ;
 

 
 void InitGrap()
 {
 	cin >> N >> K; 
 	memset(Visited, 0, sizeof(int));
 	
 	for(int i =1 ;i <= N ;i ++)
 	{
 		int p,q; 
		cin >> p ; 
		for(int j =1 ;j <= p ;j ++)
		{
			cin >> q; 			
			A[i].push_back(q);		
			//A[q].push_back(p);			
		} 	
		
		
	}
	
	for(int i =1 ;i <= N ;i ++)
		A[i].push_back(0);
		
 	
 }
 
void Visit(int u)
 {
 	cnt ++; 
 	Visited[u] =cnt;
 	pq.push(u);
 	
 	for(int i = 0, v ; v = A[u][i]  ; i++)
 	{
 		if(v != Parent[u] && !Visited[v])
 		{
 				Parent[v] = u; 
 				Visit(v);
 		}		 	
	}	
 	
 } 
 
 main()
 {
 	freopen("inEbola.txt","r",stdin);
 	
 	InitGrap();
 	Visit(K);
 	cout << cnt << endl;
 	for(int i = 1 ;i <= cnt ;i ++)
 	{
 		cout << pq.top() << " ";
 		pq.pop();
		 	
	}
 	
 }
