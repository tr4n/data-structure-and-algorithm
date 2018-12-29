#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>

#define MAX 121998
#define Base 14062008
#define For(i,a,b) for(int i = a ;i <= b ;i ++)

using namespace std; 

int F[MAX],N,K,A[MAX];

int compare( const void * a, const void * b){
	return ( *(int* ) a - *(int* )b );
}


main(){
	int N; 
	cin >> N >>K; 
	
	For(i,0,N) A[i]=0;
	
	F[0]=0;F[1]=1;F[2]=1;
	
	For(i,1,K) {
		int a; 
		cin >> a; 
		A[a]=1;
		F[a]=0;
		
	}



	int k = 1;
	For(i,3,N){
		if(A[i]!=1 && A[i-1]!=1 && A[i-2]!=1) F[i]= F[i-1]%Base+F[i-2]%Base;
		else 	if(A[i]!=1 && A[i-1]==1 && A[i-2]!=1) F[i]= F[i-2]%Base;
		else 	if(A[i]!=1 && A[i-1]!=1 && A[i-2]==1) F[i]= F[i-1]%Base;
		else   	if(A[i]!=1 && A[i-1]==1 && A[i-2]==1) F[i]= 0;
		else    if(A[i]==1) F[i]=0;
			
				
	}
	

    if(A[1]==1) cout << 0 ; else   	cout << F[N];






	
}




