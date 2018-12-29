#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  For(i,a,b) for(int i = a; i<= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define Max 11998

using namespace std ; 

main(){
	int N,C, W[Max],F[20][10000];
//	freopen("inVCOWFLIX.txt","r",stdin);
	cin >> N >> C; 
	For(i,1,N) cin >> W[i];
	For(i,1,N) F[0][i] = 0;
	For(i,1,N) F[i][0] =0;
	For(i,1,N){
		For(j,1,C){
			if(j>=W[i]) F[i][j] = max( F[i-1][j],F[i-1][j-W[i]]+W[i]);
			else {
				F[i][j]=F[i-1][j];
			}
		} 
	}
	
	cout << F[N][C];
	
	
	
}
