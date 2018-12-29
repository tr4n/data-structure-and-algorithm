#include<iostream>
#include<cmath>
#include<map>
#define For(i,a,b) for(int i =a ;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ;i --)
#define Max 1003

using namespace std;
int N,M,A[Max];
void merge(int low, int mid , int high){
	int h,i,j,b[100000],k;
	h = low ; i = low ; j = mid +1; 
	while((h<=mid )&&(j<=high)){
		if(A[h]>= A[j]){
			b[i]=A[h];
			h++;
		}else{
			b[i]= A[j];
			j++;
		}
       i++; 
		  
		  
	
	}
	if(h> mid){
		for(k = j ;k<= high; k++){
			b[i] = A[k];
			i++;
		}
	}else{
		for(k = h ; k<= mid; k++){
			b[i]= A[k];
			i++;
		}
	}
	for(k = low; k <= high; k ++) A[k]= b[k];
}
void merge_sort(int low, int high){
	int mid; 
	if(low<high){
		mid = (low + high)/2; 
		merge_sort(low, mid);
		merge_sort(mid+1,high);
		merge(low, mid, high);
	}
}



main(){
	int S = 0;
	cin >> N >> M; 
	For(i,1,M) {
		cin >> A[i];
		S+=A[i];
	}
	merge_sort(1,M);
	
	int primary =0, maxi=0;
	For(i,1,M){
		if(A[i]*i>= maxi && i<= N){
			maxi = A[i]*i;
			primary =i;
		}
		
	}
	
	cout << A[primary] << " "<< A[primary]*primary ; 
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	

