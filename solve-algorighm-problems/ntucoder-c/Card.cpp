#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <queue>

#define  For(i,a,b) for(int i =a ;i <= b ;i ++)
using namespace std;

priority_queue <int> pq;
 
 main()
 {
 	freopen("Cards.txt","r",stdin);
 	int N; 
 	cin >> N; 
 	
	 while(N--)
 	{
 		char ch[3]; 
 		cin >> ch; 
 		
		if(ch[0]=='A')
		{
			int x; 
			cin >> x; 
			pq.push(x);  	
		} 
		else if(ch[0]=='P')
		{
			if(pq.empty()) 
				cout << -1 << endl;
					
			else
			{
				int p = pq.top();
				int cnt =0;
				
				while(!pq.empty()&& pq.top()==p)
				{
					cnt ++;
					pq.pop();
				}
			
				cout << p << " " << cnt << endl;
			}
			
		}
		 	
	}
	
	if(pq.empty()) cout << -1;
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();	
	}
 	
	
 
 	
 	
 }
