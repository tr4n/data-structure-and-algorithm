#include<iostream>
#include<cstdio>
#include<algorithm>
#define For(i,a,b) for(int i = a;i <=b ;i ++)
using namespace std;
int F[42][100000001],W[42],V[42],N,M;

void QuickSort(int A[],int B[], int x, int y ){
	int v = A[(x+y)/2];
	int i = x, j = y; 
	do {
		while(A[i]<v) i++;
		while(A[j]>v) j--;
		if(i<=j ){
			if(i<j) {
				swap(A[i],A[j]);
				swap(B[i],B[j]);
			}
			i++;
			j--;
		}
			
	}while(i<=j);
	if(i<y) QuickSort(A,B,i,y);
	if(x<j) QuickSort(A,B,x,j);
}



int Init(){
	freopen("inCAITUI1.txt","r",stdin);
	//freopen("outCAITUI1.txt","w",stdout);
		
	cin >> N >> M; 
	For(i,1,N)
	 cin >> W[i] >> V[i];
	For(i,0,M)
	  F[0][i]=0;
	QuickSort(W,V,1,N);
}

int Optimize(){
	For(i,1,N)
	 For(j,0,M)
	  {
	  	F[i][j]=F[i-1][j];
	  	if(j>=W[i]&&F[i][j]<F[i-1][j-W[i]]+V[i])
	  	 F[i][j]=F[i-1][j-W[i]]+V[i];
	  }
	
}

main(){



	
		
	Init();
	int X=0;
	int k = N; 
	while(M>=1000022)
	{
		if(M>W[N]){
			X+=V[N];
			M-=W[N];
			W[N]=V[N]=0;
			N--;
		}
		else {
			W[N]=0;
			V[N]=0;
			N--;
		}
	
	}
	Optimize();
	cout << X + F[N][M];
}

