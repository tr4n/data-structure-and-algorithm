#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>

#define For(i,a,b ) for(int i = a; i<= b ;i ++ )
#define MAX 51998

using namespace std; 

int N,M,Q,K,A[MAX],P,B[MAX];

int Function1(int u, int v , int k ){
	For(i,u,v) A[i]+=k;
}

int Function2(int u, int v){
	int Max = 0; 
	int  X=u/P,Y=u/P,x,y ; 
	if(X*P!=u) {
		X++;
		x=X*P-u;
	}
	if(Y*P!=v){
		y = v-Y*P;
	}
	
	For(i,X,Y) {
		Max= max(Max,B[i]);
	}
	
	int max1=0, max2=0;
	For(i,u,x){
		max1 = max(max1,A[i]);
	}
	For(i,y,v){
		max2=max(max2,A[i]);
	}
	
	return max( max(max1,max2),Max);
	
	
	
}


main(){
	//freopen("inQMAX.txt","r",stdin);
	//freopen("outQMAX.txt","w",stdout);
	
	cin >> N >> M; 
	
	P = sqrt(N);
	
	For(i,1,P) B[i] = 0;

	For(i,1,N) A[i] = 0; 
	
	For(m,1,M){
		int u,v,k; 
		cin >> u >> v >> k ; 
		Function1(u,v,k);
	}
	
		
	For(i,1,P){
		int t = 1 ; 
		while(t<P){
			B[i]= max(B[i],A[t]);
			t++;			
		}
	}j
	
	
	cin >> Q; 
	For(q,1,Q){
		int u, v; 
		cin >> u >> v; 
		cout << Function2(u,v) << endl;
	}
	
} 



















