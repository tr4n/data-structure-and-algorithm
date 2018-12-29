#include<iostream>
using namespace std; 


main()
{
	int N, M, L, R ,A; 
	cin >> N >> M ; 
	
	int Negative[N+3], Zero[N+3];
	Negative[0] = Zero[0] = 0; 
	
	for(int i =1 ;i <= N ;i ++)
	{
		cin >> A; 
		
		Negative[i] = Negative[i-1];
		Zero[i] = Zero[i-1];
		
		if(A < 0)
			Negative[i] ++ ; 
		else
		if(A == 0)
			Zero[i] ++ ;
		
	}
	
	while(M--)
	{
		cin >> L >> R; 
		
		int N = Negative[R] - Negative[L-1];
		int Z = Zero[R] - Zero[L-1];
		
		if(Z > 0)
			cout << 0 << endl;
		else 
		if( N %2)
			cout << '-' << endl;
		else 
			cout << '+' << endl;
		
	}
	
}
