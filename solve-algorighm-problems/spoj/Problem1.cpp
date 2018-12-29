#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<bits/stdc++.h>
#include<cstring>
#include<string>
#include<stdlib.h>

using namespace std;

main()
{
	int N,K,T; 
	cin >> N >> K >> T; 
	
	if(T<= K) cout << T << endl;
	else if(T > K && T <= N )cout << K << endl;
	else if(T>N)
	{
		if(T <= N+K) cout << K - T%N << endl;
		
		
	}
	
	
	
	
}


