#include<iostream>
#include<cstdio>
#include<string>
#define ull unsigned long long
using namespace std; 

main()
{
	string S; 
	cin >> S; 
	int len = S.length();
	
	ull n  = 0 ; 
	for(int i = 0 ;i < len ;i ++)
		n+= (int)(S[i]-'0');
	 
	if(n < 10)
		cout << n << endl;
	else
	{
		int m=n;
		do
		{
			n =m;
			m = 0;
			while(n > 0)
			{
				m += (n%10);
				n/=10;
			}
			
		
		}while(m >= 10);
		
			cout << m << endl;
		
		
	}
	
	
	
	
}
