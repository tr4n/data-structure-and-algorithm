#include<iostream>
#include<cstdio>
#include<cmath>
#define For(i,a,b) for(int i = a;i <= b ;i ++)
#define Max 1000
using namespace std; 
int A[Max];
void merge(int low, int mid , int high){
	int h,i,j,b[100000],k;
	h = low ; i = low ; j = mid +1; 
	while((h<=mid )&&(j<=high)){
		if(A[h]<= A[j]){
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
	int N,B[Max];
	cin >> N; 
	For(i,1,N) cin >> A[i];
	merge_sort(1,N);
	For(i,1,N) cout << A[i]<<" "; cout << endl;
		int a = A[1];
	int k = 0 ;
	For(i,1,N){
		 
		if(a==A[i]){
			k++;
		}
		else{
			cout << a << " " << k << endl;
			k=1; a=A[i];
		}
		
		
	}
	
	cout << a << " " << k << endl;
}
