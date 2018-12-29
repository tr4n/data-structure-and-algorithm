#include<iostream>
#include<cmath>
#include<algorithm>


#define For(i,a,b) for(int i = a ; i<= b ;i ++)
using namespace std;


int Check(int N){
	int S=0;
	For(i,1,N-1){
		if(N%i==0) S+= i;
	}
	if(S>N) return 1; 
	return 0;
}


main(){
	freopen("outNKABD.txt","w",stdout);
	int N,K=0; 
	cin >> N; 
	cout << "ABD[]={";
	For(i,1,N)
	if(Check(i)==1) {
		
		K++;
		cout << i << ",";
	}
	cout << " } ;"<<endl;
	cout << "//" << K << " phan tu" <<endl;
}




