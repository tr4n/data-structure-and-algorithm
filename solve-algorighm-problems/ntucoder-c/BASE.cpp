#include<iostream>
#define ull unsigned long long
using namespace std; 



main()
{
	int T, K; 
	ull N; 
	cin >>T;
	
	while( T --)
	{
		long S = 0; 
		cin >> N >> K; 
		while(N > 0)
		{
			S += (N%K);
			N/=K;	
		}
		
		cout << S << endl;
		
	}
	
	
	
}
