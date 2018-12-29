#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>

#define For(i,a,b) for(int i = a; i <= b; i++)
#define MAX 1998

using namespace std;

void QuickSort(int A[], int x, int y){
	int k = x,v  = A[y] ; 
	
	for(int i =x ;i < y ; i ++){
		if(A[i]<=v){
			swap(A[i],A[k]);
			k++;
		}
	}
	swap(A[y],A[k]);
	
	if(x<k) QuickSort(A,x,k-1);
	if(k<y) QuickSort(A,k,y);
	
	
	
	
}

void Merge(int A[], int left, int mid, int right){
	
	int B[right-left+3];         // Initialize a array which merge two arrays (left->mid) & ( mid+1-> right)
	int k = 1, delta =left -1; 				
	int i = left, j = mid +1;	
	
	// Chose element which  = min(A[i], A[j])
	
	while(i<= mid&& j<=right){		
		B[k++] = min(A[i],A[j]);
		if(A[i] < A[j]) i++; 
		else j ++;						
	}	
	
	while(i<= mid)		B[k++] = A[i++];	
	while(j<= right)	B[k++] = A[j++];	
	
	
	// return A[i] = B[i];
	for( i = left ; i<= right ;i ++) A[i] = B[i-delta];	
}

void MergeSort(int A[], int left, int right){
	if(right<=left) return ; 
	int mid = (left + right)/2;
 	MergeSort	(A, left, mid);
	MergeSort	(A,mid+1,right);
	Merge	  	(A, left, mid, right);
	
}


main(){
	int N; 
	cin >> N; 
	int A[N+3],B[N+3];
	
	for(int i =1 ;i <= N ;i ++){
		cin >> A[i];
		B[i ] = A[i];
		
	} 
	QuickSort(A,1,N);
	for(int i =1 ;i<= N ;i ++) cout << A[i] << " ";
	cout << endl;
	int mid = (N+1)/2;
	for(int i =1 ;i <= mid ; i ++) cout << B[i] << " "; cout << endl;
	for(int i = mid+1 ;i <= N ;i ++) cout << B[i] << " " ; cout << endl;
	Merge(B,1,(int)((N+1)/2),N);
	MergeSort(B,1,N);
	for(int i =1 ;i <= N ;i ++) cout << B[i] << " ";
	
	
	
}
