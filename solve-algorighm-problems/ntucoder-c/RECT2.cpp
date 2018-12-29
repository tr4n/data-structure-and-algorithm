#include<iostream>
#include<algorithm>
using namespace std;
int A[10],B[10];
long dist(int m, int n)
{
	return (A[m]-A[n])*(A[m]-A[n]) + (B[m]-B[n])*(B[m]-B[n]);
}

main()
{
	
	for(int i =1 ;i <= 3 ;i ++)
		cin >> A[i] >> B[i];
	
	long a = dist(1,2), b = dist(2,3), c = dist(3,1);
	long Max = max(a,max(b,c));
	
	if(Max == a)
	{
		cout << A[1] + A[2] - A[3] << " " << B[1] + B[2] - B[3];
	}
	else 
	if(Max == b)
		cout <<  -A[1] + A[2] + A[3] << " " << -B[1] + B[2] + B[3];
	else
		cout << A[1] - A[2] + A[3] << " " << B[1] - B[2] + B[3];
			
	
	
}
