#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>

#define For(i,a,b) for(int i =a ;i<= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define MAX 1211998

using namespace std; 

int A[MAX],B[MAX],N, K =0,Score; 

void QuickSort(int A[],int B[], int x, int y){
	int v=A[(x+y)/2];
	int i=x,j=y;
	
	do {
		while(A[i]<v) i++;
		while(A[j]>v) j--;
		
		if(i<=j){
			if(i<j ) {
			
			swap(A[i],A[j]);
			swap(B[i],B[j]);
			
		}
	
			i++;
			j--;
		}
			
	} while(i<=j);
	
	if(i<y) QuickSort(A,B,i,y);
	if(j>x) QuickSort(A,B,x,j);

	
	
}



main(){
	
	cin >> N >> Score ; 
	
	For(i,1,N){
		cin >> A[i] >> B[i];
	}
	

	
	QuickSort(A,B,1,N);
	
	For(i,1,N){
		if(Score>= A[i]){
			Score+=B[i];
			K++;
		}
		
	}
	
	cout << K << endl;
	
}

