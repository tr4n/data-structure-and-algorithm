#include<iostream>
using namespace std; 

main()
{
	int 		N; 
	cin >> N; 
	
	int 		A[N+5];	
	long long 	S = 0, Sum = 0;
	
	for(int i =1 ;i <= N ;i ++)
	{
		cin >> A[i];
		
		S += A[i];
		
		if(S >  Sum)
			Sum = S; 
		if(S < 0)
			S= 0;
			
	}
		
	
	cout << Sum << endl;	
	
}
