#include<iostream>
#include<string>
#include<cmath>
using namespace std; 

int A; 

long long Pow(int x, int n)
{
	if(n == 0)
		return 1; 
	long long  tmp = Pow(x,n/2)%A;
	if(n% 2 == 0)
		return ((tmp%A)*(tmp%A))%A;
	else 
		return ((tmp%A)*(tmp%A)*(x%A))%A;
}



main()
{
	cin >> A; 
	
	for(int i = 1 ;i <= A ;i ++)
	{
		if(Pow(i,i) == 0)
		{
			cout << i << endl;
			break;
		}
		
	}
	
}
