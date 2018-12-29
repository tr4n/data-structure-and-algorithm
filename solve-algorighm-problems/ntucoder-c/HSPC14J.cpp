#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define MAX 1998


using namespace std;

int N,K, S[MAX];

void Prime(){
	For(i,1,MAX) S[i] = 1; 
	S[1]=0; 
	int k = 0; 
	
	int i = 2; 
	
	while(i<= N&& k<=K){
		
		if(S[i]) {
		for(int j=1;j<= N/i; j++) {
			if(S[i*j])
			 {
			 	k++;
			 	if(k==K) {
					cout <<  i*j <<endl;
					break;
				}
			 
			 }
			S[i*j]=0;
			
		
		}
		}
		
		
		i++;
	}
	
}

main(){
	while(scanf("%d%d",&N,&K)!=EOF)
	Prime();
}


