#include<iostream>
#include<algorithm>
#include<cstdlib>
#define For(i,a,b) for(int i = a ; i<= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i>= b ;i --)
#define MAX 300

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
//	freopen("inTHIDAU_NTU.txt","r",stdin);
	int N,K; 
	cin >> N>>K; 
	int A[N+3],B[N+3],F[N+3];
	For(i,1,N) cin >> A[i];
	For(i,1,N) cin >> B[i];
	
	QuickSort(A,B,1,N);
	
	F[0]=0;
	For(i,1,N) F[i] = B[i];
	
	int Ans = 0;
	
	For(i,1,N){
		For(j,1,i-1){
			if(A[i]-A[j]>=K){
				F[i] = max(F[j]+B[i],F[i]);
			}
			
		}
		Ans = max(Ans,F[i]);
	}
	
	cout << Ans << endl;
	
}
