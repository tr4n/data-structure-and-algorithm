#include<iostream>

using namespace std;


int BinarySearch( int A[], int a, int b, int x){
	int i = a, j = b;
	while( i < j){
		int k = ( i+j )/2;
		if( x < A[k]) j = k-1;
		else if( x == A[k] ) return k;
		else i = k+1;
	}
	if(A[i]<x) return i+1;
	else  return i ; 
}
main(){
	int a[100003],p[10003],A[100003],n,m;
	cin >> n;
	for( int i = 1; i <= n; i++) cin >> a[i];
	
	A[1] = a[1];
	cin >> m;
	for( int i = 1; i <= m; i++) cin >> p[i];
	for( int i = 2; i <= n; i++) A[i] = A[i-1] + a[i];
	for(int i = 1; i <= m; i++){
		cout << BinarySearch(A,1,n,p[i]) << " " ;
	}
}
