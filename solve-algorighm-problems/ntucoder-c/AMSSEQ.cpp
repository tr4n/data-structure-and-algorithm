#include<iostream>
#include<cmath>
#include<cstdio>
#define For(i,a,b) for(int i = a;i <= b ;i ++)
#define Max 11000

using namespace std; 


main(){
	int N,K,A[Max],F[Max][20]; 
	cin >> N >> K ; 
	int Min=99999; 
	For(i,1,N) {
		cin >> A[i];
		if(Min>= A[i]) Min =A[i];
	}
		
	For(i,1,N) F[i][0] = A[1];
	For(i,0,K) F[0][i] =0;
	
	For(i,1,N){
		For(j,1,K){
			int M = N*Min;
			For(t,1,j){
				if(i-t>= 0){
					if(M<= A[i]+ F[i-t][j]) M = A[i]+ F[i-t][j];
					
				}
			}
			F[i][j] = M; 
		}
	}
	int ans  = F[1][K];
	For(i,1,N) {
		if(ans <= F[i][K]) ans = F[i][K];
	
	}
	cout << ans; 
	
	
}
