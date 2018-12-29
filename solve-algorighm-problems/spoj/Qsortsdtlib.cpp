#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define For(i,a,b) for(int i = a ;i <= b ;i ++)

using namespace std; 

int compare ( const void* a, const void* b){
	
	return *(int*)a - *(int*)b;
}





main(){
	priority_queue <int, vector<int>,greater<int>  > pq; 
	int N; 
	cin >> N; 
	//int A[5000];
	For(i,0,N-1 ) {
		int a; 
		cin >> a; 
		pq.push(a);
		
	}
	
	while(!pq.empty()){
		cout << pq.top()<< endl;
		pq.pop();
		
		
	}
	
//	qsort(A,N,sizeof(int),compare);
	
	
//	int key; 
	
	
	
//	For(i,0,N-1) cout << A[i] << endl;
	
	
}










