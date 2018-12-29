#include<iostream>
#include<cstdio>
#include<algorithm>

#define For(i,a,b) for(int i = a ;i <= b ;i ++)

using namespace std; 



int Fr(int N){
	int X = 0 ; 
	while(N!=0){
		X= (X)*10 + N%10; 
		N/=10;  
	}
	
	return X; 
	
	
}

int UCLN(int a,int b){
	
	
	while(a %b !=0){
		int r = a%b ; 
		a=b ; 
		b = r;
	}
	
	return b ; 


}


main(){
//	freopen("outPNUMFRE.txt","w",stdout);
	int A,B; 
	cin >> A >> B ; 
//	cout << " Friend[]={";
	int cnt = 0 ; 
	For(i,A,B){
		
		if(UCLN(i,Fr(i))==1){
		//	cout << i << " , ";
			cnt++;
		}
	}
	
//	cout <<cnt << " }";

cout << cnt ; 
}



















