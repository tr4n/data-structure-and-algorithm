		#include<iostream>
		//#include<bits/stdc++.h>
		#include<algorithm>
		#include<cstdlib>
		
		#define For(i,a,b) for(int i = a ;i <= b ;i ++)
		#define FOR(i,a,b) for(int i = a; i>= b ;i --)
		#define MAX 100
		using namespace std;
		
		
		main(){
		//	freopen("inBUBE.txt","r",stdin);
			int N,K; 
			cin >> N>> K; 
			
			int A[N+3];
			
			
			For(i,1,N) cin >> A[i];
			sort(A+1,A+N+1);
			
			int M = N; 
			unsigned long long int Sum = 0; 
			FOR(i,N,1){
				if(A[M]-A[i]>=K) M--;
				else Sum+= A[i];
				
			}
			
			cout << Sum; 
			
		}
