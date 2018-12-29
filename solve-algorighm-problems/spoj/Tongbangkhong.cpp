#include<iostream>
#include<cstdio>

#define For(i,a,b) for(int i =a ; i<= b ;i ++)
#define MAX 1211998
using namespace std; 

int A[MAX], N,K=0; 

main(){
	cin >> N ; 
	For(i,1,N ) cin >> A[i];
	int B[N*N+3],C[N*N+3],S[N*N+3];
	For(i,1,N-1){
		For(j,i+1,N){
			K++;
			S[K]= A[i]+A[j];
			B[K]=i;
			C[K]=j;		
			
		}
	}
	
	
	For(i,1,K){
		For(j,1,N){
			
			if(A[j]+S[i]==0 && j!=B[i]&&j!=C[i]) {
				cout << A[B[i]] << " +" << A[C[i]] << " + " << A[j] << " = 0" << endl; 
				
			}
		}
		
	}
	
	
}


