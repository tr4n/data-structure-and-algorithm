#include<iostream>
#include<cstdio>
#include<algorithm>

#define For(i,a,b) for(int i = a ;i<= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define MAX 1998

using namespace std;


int N,A[MAX],B[MAX],F[MAX][MAX];

int compare(const void* a, const void* b){
	return ( *(int*)a - *(int*) b  );
	
}


main(){
	 
	
	cin >> N; 
	For(i,0,N-1) {
		cin >> A[i];
		B[i] = A[i];
	}
	
	qsort(B,N,sizeof(int),compare);
	
	For(i,0,N) F[i][0] = F[0][i] = 0 ; 
	
	
	For(i,0,N-1){
		For(j,0,i){
		
		if(A[i]==B[j]&& i!=j){
			F[i][j] = F[i-1][j-1]+1;
		}
		else F[i][j] = max(F[i-1][j],F[i][j-1]);
		
		
		}
	}
	
	cout << F[N-1][N-1];
	
	
} 

