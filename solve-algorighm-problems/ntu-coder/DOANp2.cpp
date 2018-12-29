#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cmath>

#define Base 1998
#define For(i,a,b) for(int i = a ; i<= b ;i ++)
#define Max 111998
#define ll long long 
#define ull unsigned long long
using namespace std; 


 int A[Max],B[Max],N;
 long int BASE;

int compare(const void* a, const void*b){
	return *(int*)a - *(int*)b;
}

void QuickSort(double A[],int B[],int C[], int x, int y){
	int v=A[(x+y)/2];
	int i=x,j=y;
	
	do {
		while(A[i]<v) i++;
		while(A[j]>v) j--;
		
		if(i<=j){
			if(i<j ) {
			
			swap(A[i],A[j]);
			swap(B[i],B[j]);
			swap(C[i],C[j]);
		}
	
			i++;
			j--;
		}
			
	} while(i<=j);
	
	if(i<y) QuickSort(A,B,C,i,y);
	if(j>x) QuickSort(A,B,C,x,j);

	
	
}

int Size(int N){
	int k = 1 ; 
	while(N>0){
		N/=10;
		k*=10;
	}
	return k; 
}

main(){
	freopen("inDOANP2.txt","r",stdin);
	
	cin >> N; 
	
	int M = -1;
	
	double C[N+3];
	For(i,0,N-1) {
		cin >> A[i]>> B[i]	;
		M = max(M,B[i]);
		
	}
	
	BASE = Size(M);

	For(i,0,N-1){
		C[i] = A[i] + B[i]/BASE;
		
	}
	

	QuickSort(C,A,B,0,N-1);

	ull S = B[0]-A[0];

	For(i,0,N-2){
		if(A[i+1]<B[i]&& B[i]<B[i+1]){
			S+= B[i+1]-B[i];

		}
		else if ( A[i+1]>=B[i]){
			S+= B[i+1]-A[i+1];
	
		}
		else if ( B[i+1]<= B[i]){
			B[i+1] = B[i];
		}
	
		
		
	}
	
	cout << S << endl;
}
