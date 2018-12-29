#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define For(i,a,b) for(int i = a ;i<= b ;i ++)
#define FOR(i,a,b) FOR(int i = a ;i>=  b;i --)
#define MAX 55555
using namespace std;

int A[MAX],minSum,Sum[MAX],maxSum= -MAX;

int N,M,x,y;




main(){
	freopen("inGSS.txt","r",stdin);
//	freopen("inGSS.txt","r",stdin);
	
	Sum[0] = 0 ; 
	cin >> N; 
	
	
	For(i,1,N){
		cin >> A[i];
		Sum[i] = Sum[i-1] + A[i];
		maxSum = max(maxSum,Sum[i]);
	}
	

	


		
		minSum = 0; 
		int Res[MAX];
		For(i,1,N) Res[i] = -MAX;
		int Ans = -MAX ;
		For(i,1,N){
			
			Res[i] = max(Res[i],Sum[i]-minSum);
			minSum= min(minSum,Sum[i]);
						
		}
		For(i,1,N){
			if(Res[i]%3==0){
				Ans = max(Ans, Res[i]);
			}
		}
		
		cout << Res ; 



}
	
	
	
	
	
	
	
	

