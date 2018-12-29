#include<iostream>
#include<cmath>
#include<stack>
#define BASE 10000
#define MOD(a) (a%BASE+BASE)%BASE
#define ll long long
using namespace std; 



main()
{
	int x;
	ll n;
	cin >> x >> n; 
	
	stack <ll> St;
	long long  tmp = 1; 
	 
	while(n>0)
	{
		St.push(n);
		n/=2;		
	}
	
	if(St.empty()) 
		cout << tmp << endl;
	else
	{
		while(!St.empty())
		{
			int m = St.top();
			if(m%2)
				tmp = (ll)((tmp % BASE)*(tmp %BASE)*(x %BASE))%BASE;
			else
				tmp = (ll)((tmp %BASE)*(tmp%BASE))%BASE;
			
			St.pop();	
		
		}	
		cout <<  tmp << endl;
	}
	
	
	
	
	
	
	
}
