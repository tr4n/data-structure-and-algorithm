#include<iostream>
#include<cmath>
using namespace std; 



main()
{
	string base = "abcdefghijklmnopqrstuvwxyz";
	int BASE = base.length();
	string S; 
	int K; 
	cin >> S; 
	cin >> K; 
	
	for(int i = 0 ;i < S.length(); i++)
	{
		for(int j = 0 ;j < BASE; j++)
		{
			if(S[i] == base[j])
			{
				cout << base[(j-K+2*BASE)%BASE];
				break;
			}
		}
	}
		
	
}
