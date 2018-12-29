#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std; 


main()
{
	bool Stand[51000];
	
	string S; 
	cin >> S; 
	
	int F[51000];
	F[0] = 0;
	int len = S.length();
	S= " "+S;
	int t = 0;
	for(int i = 1 ;i <= len ; i++)
	{
		S[t] = S[i];
		for(int j = i-1 ; j >= t ;j--)
		{
			if(S[i] == S[j])
			{
				t = j;
				F[i] = i-t;
				break;	
			}
		}
	}
	
	int res = -1;
	int pos = -1;
	for(int i = 1 ;i <= len ;i ++ )
	{
		if(F[i] > res)
		{
			res = F[i];
			pos = i;	
		}	
	}
	
	
		
	cout << res << endl;
	
	
	
}
