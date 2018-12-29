#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#define For(i,a,b) for(int i = a ;i <=  b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define Max 2998

using namespace std; 

char A[Max],B[Max],C[Max];

void parline(char A[], char B[]){
	int a = strlen(A),k=0;
	FOR(i,a-1,0){
		B[k]=A[i];
		k++;
	}
	B[a]='\n';
	
}
 int L[Max][Max],k=0,n;
int  trace( int P[], int a, int b){
	
	if(b>=0 &&a>=0){
		
	if(L[a][b]==L[a-1][b-1]+1) {
	cout << A[n-b] ;
	
	//P[k]=b;	
	//k++;
	trace(P,a-1,b-1);
	}
	else {
		trace(P,a,b-1);
	}
	}
}

main(){
//	freopen("inNKPALIN.txt","r",stdin);
	
//	int L[Max][Max];
	cin >> A; 
	parline(A,B);
//	cout << B << endl;
	 n = strlen(A);
	For(i,0,n) {
		L[0][i]=0;
		L[i][0]=0;
	}
	For(i,1,n){
		FOR(j,n,1){
			if(A[i-1]==B[j-1]){
				L[i][j]=L[i-1][j-1]+1;
			}
			else {
				L[i][j]=max(L[i][j-1],L[i-1][j]);
			}
		}
	}
	
	
	int P[Max],m=0,pos =0;
	For(i,1,n) {
		if(L[n][i]>= m) {
			m = L[n][i];
			pos = i ; 
		}
	}
    trace(P,n,pos);
//	 cout << endl;
//   // For(i,0,k) cout << A[P[i]-1]; cout << endl;
//  For(i,1,n){
//	For(j,1,n){
//		cout << L[i][j]<<" ";
//	}
//	cout << endl;
//}


}



