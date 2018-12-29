#include<iostream>
#include<cstdio>
#include<queue>

#include<queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i = a;i <= b ;i ++)
#define FOR(i,a,b) for(int i  = a ;i >= b ;i --)
#define Max 121998
using namespace std; 

vector <int> A[Max];
int cnt=0,N,M,K,n=0;

int Visited[Max], Parent[Max],B[Max];

void Visit(int u){
//	cout << "Visit "<< u << endl;
	B[++n] = u;
	Visited[u]=++cnt ; // travesal time
	for(int i = 0 ,v ; v = A[u][i] ; i ++ ){
		if(v!= Parent[u]){
			Parent[v] = u ; 
			Visit (v);
		}
	}
}

void Init(){
	cin >> N >> K; 
	For(i,1,N){
		
		int M ; 
		cin >> M; 
		while(M--){
			int x ; 
			cin >> x ; 
			A[x].push_back(i);
			A[i].push_back(x);
		}
		int p,q; 
		
	}
	For(i,1,N) A[i].push_back(0);
	
}

void DFS(){
	Visit(K);
}

main(){
	Init;
	DFS;
	sort(B+1,B+n+1);
	For(i,1,n) cout << B[i] << " ";
	
	
}

