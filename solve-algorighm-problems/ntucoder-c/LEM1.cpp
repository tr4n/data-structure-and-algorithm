#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define For(i,a,b) for(int i = a ; i<= b ;i ++)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132
using namespace std; 

int Factorial[]={1,1,2,6,24,120,720,5040,40320,362880};

float Cout (float val){
	
	return  roundf(val*100000)/100000 ;
}
 // std::cout << roundf(val * 100) / 100 << std::endl;
 
 float Sin(float X){
 	
 	return X-X*X*X/Factorial[3]+X*X*X*X*X/Factorial[5]-X*X*X*X*X*X*X/Factorial[7]+X*X*X*X*X*X*X*X*X*X*X/Factorial[9];
 	
 	
 }

main(){
	int N;
	cin >> N; 
	float S = 0;  
	For(i,1,N){
		float r; 
		cin >> r;
		S+=r; 
		
	}
	
//	float a = 2*S/N; 
	
	cout << Cout( S/(N*Sin(PI/N))-S/N  )<< endl;
	
}
