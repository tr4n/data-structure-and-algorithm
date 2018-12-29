#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>

#define For(i,a,b) for(int i = a ;i  <= b ;i ++)
#define FOR(i,a,b) for(int i =a ;i >= b ;i --)
#define MAX 15555

using namespace std; 



main(){
	freopen("cineof.txt","r",stdin);
	priority_queue <int> pq,pq1; 
	string S; 
	//cin >> S; 
	int L = 0 ;
	
	while(cin>> S){

	
		if(S[0]=='+' && pq.size()<=15000){
			
			int V=0;
		
			For(i,1,S.length()-1){
				V=V*10+ int(S[i]-'0');
			}
			
		//	cout << V << endl;
			pq.push(V);
		
			
			
		}
		else 
		if(S[0]=='-'&&!pq.empty()){
			int v = pq.top();
		//	cout << "top " << v << endl;
			while(!pq.empty() && v==pq.top()) {
				
				pq.pop();
			}
			
			
		}
		
	}
	
	int P[MAX],Q[MAX];
	if(pq.empty()) {
		cout << 0 << endl;
		return 0 ; 
	}
	
	int N=0; 
	
	int Top= pq.top();
	pq1.push(Top);
	
	while(!pq.empty()){
		pq.pop();
		if(pq.top()!=Top){
			Top=pq.top();0.052.0
			pq1.push(Top);
		}
	}
	
	/*
	Q[1]=P[1];
	int X = P[1];
	L=1;
	
	For(i,2,N){
		if(P[i]!=X){
			L++;
			Q[L]= P[i]; 
			X = P[i];
			
		}
	}
	
	cout << L << endl;
	For(i,1,L) cout << Q[i] << " ";
	
	*/
	
	cout << pq1.size()<< endl;
	
	while(!pq1.empty()){
		cout << pq1.top()<< " "; 
		pq1.pop();
	}
		
	
}
