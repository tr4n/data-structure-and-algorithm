#include<iostream>
#define ull unsigned long long
using namespace std; 

main()
{
	int N; 
	cin >> N; 
	int a;
	double RES ; 
	ull odd = 0, even = 0;

	for(int i =1 ;i <= N ;i ++) 
	{
		cin >> a; 
		if(a %2) 
			even ++ ;
		else 
			odd ++;
	}

	if(1 == even %2)
	{
		cout << (ull)(even*odd) << endl;
	}
	else
	{
	
		RES=  (double)(0.5*odd*(odd -1) +(double)(0.5*even*(even-1)) );
		cout << (ull)(RES )<< endl;	
	}
	
	
	
}
