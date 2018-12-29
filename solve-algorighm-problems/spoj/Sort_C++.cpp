#include<iostream>
#include<algorithm>
#include<cstdlib>
#define For(i,a,b) for(int i = a ; i<= b ;i ++)

using namespace std; 


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
	int N; 
	cin >> N; 
	int A[N+3];
	For(i,0,N-1) cin >> A[i];
	qsort(A,N,sizeof(int),compare);
	
	For(i,0,N-1) cout << A[i]<< " ";
	
}
