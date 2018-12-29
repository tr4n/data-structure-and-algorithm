#include<iostream>
#include <cmath>
#include <cstdio>
#define For(i,a,b) for(int i = a;i <= b ;i ++)
#define Max 1998
using namespace std;

int N, K, A[Max],F[Max][Max]; 
int Sub_mod(int a, int b){
	int q  = (a-b)%K;
	if (q<0) return (q+K);
	else return q;
}
main(){
	freopen("inQBSEQ.txt","r",stdin);
	
	cin >> N >> K ; 
	A[0]=0;
     For(i,1,N) {
	 			cin >> A[i];
 	 			A[i]%=K;
	 			}
	 			
 	
 	 For(i,0,K) F[0][i]=-999;
 	 F[0][0]=0;
 	 For(i,1,N){
 	 	For(j,0,K-1) F[i][j]=max(F[i-1][j],F[i-1][Sub_mod(j,A[i])]+1);
	  }
	
//	For(i,1,N) cout << A[i] << " ";cout << endl;
//	For(i,0,N){
//		For(j,0,N) cout << F[i][j]<<" ";
//		cout << endl;
//	}
	cout << F[N][0];
}
