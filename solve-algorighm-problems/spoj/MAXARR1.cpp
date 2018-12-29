#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int  i = a;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define Max 200001

using namespace std; 

main(){
	   int T,A[Max];
	   A[0]=0;A[1]=1; 
	   
	   cin >> T; 
	   For(i,2,100000){
	   		if (i%2==0) A[i]= A[i/2];
	   		else A[i] = A[(int )(i-1)/2] + A[(int)(i+1)/2];
		   };
		   
	   int F[Max];
	   F[0]=0;
	   F[1]=1;
	   F[2]=1;
	   For(i,1,100000){
	   	 if(A[i]> F[i-1]) F[i]=A[i]; 
	   	 else F[i]=F[i-1];
	   }
	   For(t,1,T){
	   	int N; 
	   	cin >> N; 
	   	cout << F[N]<< endl;;
  		  
	   };
	
	
}
