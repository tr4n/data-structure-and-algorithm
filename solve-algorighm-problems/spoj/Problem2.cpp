#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<bits/stdc++.h>
#include<cstring>
#include<string>
#define ll unsigned long long
#define PI 3.14159265359


using namespace std;


int a1,a2,b1,b2,c1,c2;


bool Check()
{
	ll x = (ll)((b1-a1)*(ll)(c2-a2) ); 
	ll y = (ll)((c1-a1)*(ll)(b2-a2)) ;
	if((ll)(x) == (ll)(y)) return false;
	
	return true;
	
}


main()
{
//	freopen("inP2.txt","r",stdin);
	
	
	
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 ; 

	ll  AB = (ll)(b1-a1)*(b1-a1) + (ll)(b2-a2)*(b2-a2);
	ll  BC = (ll)(c1-b1)*(c1-b1) + (ll)(c2-b2)*(c2-b2);
	
	if(Check())
	{
		if((ll)AB == (ll)BC) cout << "Yes" ; 
		else 
			cout << "No" << endl;
		
	}
	else 
		cout << "No" << endl;
	
	
	
}



