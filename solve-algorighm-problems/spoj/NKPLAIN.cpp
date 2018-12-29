#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
#define Max 2025

main(){

	char x[Max];
	cin >> x;
	int i,j,N=strlen(x);
	int X[N+2];
	for(i=1;i<=N;++i) X[i]=x[i-1]-'a';X[N+1]=0;
	
	char Y[N+5];
	for(i=1 ; i<=N ;++i) Y[i]=X[N-i+1];	Y[N+1]=0;
	
	int F[N+3][N+3];
	for(i=0 ; i<=N; i++) {
		F[i][0]=0;
		F[0][i]=0;
	}

	for(i=1; i<=N;i++)
		for(j=1;j<=N;j++){
			
			if(X[i]==Y[j])	F[i][j]= F[i-1][j-1]+1;
			else F[i][j]=max(F[i-1][j],F[i][j-1]);
		}

	i=N;
	j=N;
	while(i>0&&j>0)
		
		{
			if(X[i]==Y[j]){
				cout <<(char)(X[i]+'a');
				i--;
				j--;
			}
			else {
				if(F[i][j]==F[i-1][j]) i--;
				if(F[i][j]==F[i][j-1]) j--;
					
				}
				
				
				
			
			
		}

}

