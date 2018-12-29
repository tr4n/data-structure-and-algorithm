#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std; 

#define For(i,a,b) for(int i = a ;i <= b ;i ++)
#define MAX 2111998

int N, A[MAX] ;

main(){
	cin >> N; 
	
	int M[2*N+1] ;
	
	M[0] = 0 ; 
	For(i,1,N) {
		cin >> A[i];
		M[0]+=A[i];
	}
	For(i,N+1,2*N-1) A[i]= A[i-N];
	
	
	
	For(K,1,N-1){
		int S = 0;
		
		For(j,1,K) S += A[j]; 
		
		 M[K] = S;
		
		For(i,2,N-1){
			if(M[K] <  S-A[i-1]+A[i+K-1]){
				M[K] = S-A[i-1] + A[i+K-1];				
			}
			S += A[i+K-1]-A[i-1];
			
		} 
		
	}
	
	int Max = M[0];
	For(i,1,N-1){
		Max = max(Max,M[i]);
	}
	cout << Max ; 
}


