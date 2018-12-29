#include <iostream>
#include <cmath>
#define For(i,a,b) for(int i = a ;i <= b ;i ++)
using namespace std ; 

main(){
//	freopen("input.txt", "r", stdin);
	int M,N;
	cin >> M >> N; 
	int A[M+2][N+2];
	For(i,1,M)
	 For(j,1,N)  cin >> A[i][j];
	int L[M+2][N+2];
	For(i,0,N+1) {
	 L[M+1][i]=-20000; }
	For(i,0,N+1) L[0][i]=-20000;

	For(i,1,M) L[i][1]= A[i][1];
	For(j,2,N)
	    For(i,1,M) L[i][j] =A[i][j]+ max(max(L[i+1][j-1],L[i-1][j-1]),L[i][j-1]);
			
	int Max = -20000 ; 
	For(i,1,M)  if(Max < L[i][N]) Max = L[i][N];

	
	cout << Max ; 
	
	
}
