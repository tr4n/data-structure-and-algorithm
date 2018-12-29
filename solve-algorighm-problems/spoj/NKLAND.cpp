#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define For(i,a,b) for(int i = a ;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define MAX 1998
#define Alpha k*PI/100

#define PI 3.14159265358979

using namespace std;
int N,M,T,a1[MAX],b1[MAX],a2[MAX],b2[MAX];
double  X1[MAX],Y1[MAX],X2[MAX],Y2[MAX] ;

main(){
	freopen("inNKLAND.txt","r",stdin);
	cin >> T; 
	while(T--){
		cin >> M ;
		For(i,1,M){
			
			cin >> a1[i] >> b1[i];
					
		}
		
		
		cin >> N; 
		For(i,1,N){
			cin >> a2[i] >> b2[i];
					
		}
	
		int k = 1,Check = 0;;
		while(k<=200 && !Check){
			For(i,1,M){
				X1[i] = a1[i] * cos(Alpha) - b1[i] * sin(Alpha); 
				Y1[i] = a1[i] * sin(Alpha) - b1[i] * cos(Alpha);
			}
			double X1max ,X1min ; 
			X1max = X1min = X1[1];
		
			For(i,2,M) {
				X1max = max(X1max,X1[i]);
				X1min = min(X1min,X1[i]);
			}
			
			For(i,1,N){
				X2[i] = a2[i] * cos(Alpha) - b2[i] * sin(Alpha); 
				Y2[i] = a2[i] * sin(Alpha) - b2[i] * cos(Alpha);
			}
			
			double X2max ,X2min ; 
			X2max = X2min = X2[1];
		
			For(i,2,N) {
				X2max = max(X2max,X2[i]);
				X2min = min(X2min,X2[i]);
			}
			
			if(X1max <= X2min || X1min >= X2max) Check =1 ; 
			k++;
			
		}
		
		if(Check==1) cout << "NO" << endl;
		else cout << "YES" << endl;
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
}

