#include<iostream>
#include<cstring>

using namespace std; 

main(){
	string S; 
	int A[15];
	for(int i =0 ;i <= 9 ;i ++ ) A[i] = 0;
	
	cin >> S; 
	for(int i = 0; i< S.length();i++)
		if(S[i]>='0'&&S[i]<='9') A[(int)(S[i]-'0')]++;
				
		
	for(int k = 9 ; k>=0 ;k--)
		for(int i = 1; i<= A[k] ;i++) cout << k;
		
}
