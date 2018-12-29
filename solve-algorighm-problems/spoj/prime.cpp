#include <iostream>
#include <cmath>
#include <cstdio>
#define  For(i,a,b) for(int i = a; i<= b; i++)
#define Max 100000

using namespace std;
int Prime(int N){
	int Check =1, i =2 ;
	if (N <2) Check =0 ; 
	else 
	if(N==2 || N==3 || N==7) Check ==1; 
	else 
	while (Check ==1 && i <= sqrt(N)){
		 if( N %i ==0 ) Check =0;
		 else i ++;
	}
	return Check ; 
}
main(){
	int T ; int C[Max+3];
	For(i,0,Max) C[i] =0; 
	cin >> T;
	 
	For(t,1,T){
		int A,B; 
		cin >> A >> B;
		For(i,A,B){
			if(C[i]==0) {
				int P = Prime(i);
				if(P==1) {
					C[i]=1;
					cout << i << endl;
				}
			} else cout << i<< endl;
		} 
		
		
		
	}
	
}
