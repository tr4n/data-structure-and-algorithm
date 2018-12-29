#include<iostream>
#include<cmath>
using namespace std; 

main()
{
	int M,N; 
	string S; 
	cin >> M >> N; 
	int len = M+N;
	cin >> S; 
	S[len] = S[0];
	
	for(int i = 0 ;i < len ;i ++ )
	{
		if(S[i] == 0 && S[i+1] == 0)
			M ++;
		if(S[i] == 1 && S[i+1] == 1)
			N++;
	}
	cout << abs(M-N);
	
}
