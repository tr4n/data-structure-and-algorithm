#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,a,b) for(int i = a;i <= b;i ++)
#define FOR(i,a,b) for(int i = a;i >= b ;i --)
#define Max 1000

using namespace std;

int N, A[Max][Max],T[Max];

int getBit(int state , int j){
	return (state >> j) && 1; 
}

int TurnOff (int x , int i) {
	 return x && not (1 << i)  ; 
}

int getMax(int state){
	int k = 0,B[Max] ; 
	For(i,0,(1<<Max)-1) B[i]=0;
	For(i,1,N){
		if(getBit(state,i-1)==1){
			k++ ; 
			B[k]=i;
		}
	}
	
	int MAX = -9999999999 ,preState; 
	
	For(j,1,k ){
		preState = TurnOff(state, B[j]-1);
		if(MAX < T[preState] + A[k][B[j]]){
			MAX = T[preState] + A[k][B[j]];
		}
		
		
	}
	 return MAX; 
	
} 

main(){
	   freopen("QBSELECT.txt","r",stdin);
	   cin >> N; 
	   For(i,1,N){
	   	For(j,1,N){
	   		cin >>  A[i][j];
		   }
	   }
	   T[0]= 0 ;
	   int first = 1, last = (1 << N)-1; 
	   cout << last << endl; 
	   For(i,1, last){
	   	T[i] = getMax(i);
	   	cout << T[i] << " ";
	   }
	   cout << endl;
	   
	  // For(i,1,N) cout<< T[i] << " ";
	
	
	
}
