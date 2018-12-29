#include <iostream>
#define For(i,a,b) for(int i = a; i<= b ;i ++)
#define FOR(i,a,b) for(int i = a; i>= b ;i ++)

using namespace std ; 
int A[100000];
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
int UCLN(int a,int b){
	
	if(a%b!=0) return UCLN(b,a%b);
	else return b; 
	
//		while(a %b !=0){
//		int r = a%b ; 
//		a=b ; 
//		b = r;
//	}
	
	//return b ; 



}
main(){
      int a,b; 
      cin >> a >> b; 
      
      cout << UCLN(a,b);
}

