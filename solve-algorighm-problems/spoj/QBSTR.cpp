#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define For(i,a,b) for(int i = a ; i<= b ;i ++)
#define Max 1000
using namespace std; 

main(){
	//freopen("inqbstr.txt","r",stdin);
	char A[Max],B[Max],C[Max];
	int L[Max][Max];
	cin >> A ; 
	cin >> B; 
	int N = strlen(A), M = strlen(B);
	For(i,0,M){
		L[0][i]=0;
	}
	For(i,0,N) L[i][0]=0;
	For(i,1,N){
		
		For(j,1,M){
			if(A[i-1]==B[j-1]) {
			 L[i][j]=L[i-1][j-1]+1;
			
			 }
			else L[i][j] = max (L[i-1][j],L[i][j-1]);
			
		}
		
	} 
	 cout << L[N][M];
	
	
}
