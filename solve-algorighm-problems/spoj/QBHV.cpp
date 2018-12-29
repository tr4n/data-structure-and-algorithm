#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>

#define For(i,a,b) for(int i = a ;i <= b ;i ++)

using namespace std;

// Khai Bao
int Factorial[]={1,1,2,6,24,120,720,5040,40320,362880};

int N, K = 0 ,A[20], B[20],C[20],D[20];

int Used[20];

//priority_queue <string> pq;
    

//-----------------------------
struct cmp{    bool operator() (string a,string b) {        return a<b;    }};
//--------------

 priority_queue<string,vector<string>, greater<string> > pq;  



int Show(){
	string S="";
	For(i,1,N){
		S+= (char)(D[i]+(int)'A'-1);
	}
	
//	cout << S ;
	pq.push(S);
//	cout << endl;
}


int Try(int pos){
	
	if(pos==N+1){
		Show();
		return 0 ; 
	}
	For(i,1,N){
		if(!Used[i]){
			Used[i]=1;
			D[pos]=A[i];
			Try(pos+1);
			Used[i]=0;
		}
		
	}
	
}





// Main
main(){
	char S[20];
	cin >> S; 
	
	N = strlen(S);
	
	For(i,0,N-1){
		A[i+1] = S[i]-(int)'A'+1;
	}
	
	For(i,1,N-1){
		For(j,i+1,N){
			if(A[i]>A[j]) swap(A[i],A[j]);
		}
	}
	
//	For(i,1,N) cout << A[i] << " ";cout << endl;
	

	
	B[K]=0;
	For(i,1,N) C[i]=0;
	
	For(i,1,N){
		if(A[i]!=B[K]){
			K++;
			B[K]=A[i];
			
		}
		
		C[K]++;
		
	}
	
	int P=1; 
	For(i,1,K) P*= Factorial[C[i]];
	
	cout << Factorial[N]/P << endl;

// Back_Track
	
	For(i,1,N) Used[i]=0;
	
	Try(1);
	
	string str = pq.top();
	
	
	while(!pq.empty()){
		
		pq.pop();
		if(str!=pq.top()) {
			
			cout << str << endl;
			str=pq.top();
			
		}
		
	
		
		
		
		
	}
	
	cout << str << endl;
	
	
	
	
	
	
	
	
}

