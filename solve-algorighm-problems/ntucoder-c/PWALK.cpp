#include<iostream>
#include<cstdio>
#include<queue>

#include<queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#define For(i,a,b) for(int i = a ;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define Max 1008
using namespace std; 

vector<int> A[Max]; 
int N,Q , Visited[Max], cnt = 0,Parent[Max];
int L[Max][Max]; 

int Len = 0  ; 


void DFS(int u){
	
    Visited[u] = ++cnt; 
    
    for(int i = 0 , v ; v= A[u][i];i ++){
    	if(Parent[u]!=v){
    		Parent[v] = u; 
    		
    		DFS(v);
		}
	}
}

void Init(){
	cin >> N >> Q; 
	For(i,0,N) {
		L[0][i]=0; L[i][0]=0;
	}
	For(i,1,N-1){
		int p,q,x; 
		cin >> p >> q >> x ;
		L[p][q]=x;
		L[q][p] = x;
		A[p].push_back(q);
		A[q].push_back(p);
	}
	
	For(i,1,N) A[i].push_back(0);
}


main(){
	freopen("PWALK.txt","r",stdin);
	Init();
	
	For(t,1,Q){
		int p1,p2; 
		For(i,0,N) Parent[i]=0;
		
		
		Len  = 0 ; 
		cin >> p1 >> p2 ; 
		DFS(p1);
		int k=p2;
		while(Parent[k]!=p1){
			Len+= L[Parent[k]][k];
			k = Parent[k];
		}
		Len += L[Parent[k]][k];
		cout << Len << endl;
		
	}
	
}


