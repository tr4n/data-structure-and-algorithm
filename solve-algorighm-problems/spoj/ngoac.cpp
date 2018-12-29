#include<iostream>
#include<cstring>

#define Max 1998

#define For(i,a,b) for(int i = a ;i <= b ;i ++)

using namespace std ; 

main(){

	 freopen("outFERFECT.txt","w",stdout);
	int n=0; 
	cout << " PERFECT[]={";
	For(N,1,10000000){
	 
	int S = 0 ; 
	For(i,1,N-1){
		if(N%i==0)S+=i;
		if(S>N ) break;
	}
	
	if (S==N)  {
	n++;	
	cout << N << ",";
	}
	}
	
	cout << n << "}"; 
}
