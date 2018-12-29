#include<iostream>
#include<cstdio>
using namespace std; 

main()
{
	long long T, X, Y, C; 
	cin >> T; 
	while(T--)
	{
		cin >> X >> Y >> C ; 
		
		if(C*C >= 2*X*Y)
			cout << "DANGER"  << endl;
		else 
			cout << "SAFE" << endl;
	}
	
}
