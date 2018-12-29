#include<iostream>
#include<cmath>

#define PI 3.14159265359
using namespace std; 

main()
{
	int n, R, r; 
	
	cin >> n >> R >> r; 
	
	if(n == 1)
	{
		if(R >= r) cout << "YES";
		else cout << "NO";
		
	}
	else
	{
		double t = r / sin(PI/n);
	
		cout << (double)t << " " << R-n;
		if( (double) t >= (double)(R-r)) 
			cout << "NO"; 
		else cout << "YES";
	}
	
	
	
	
}
