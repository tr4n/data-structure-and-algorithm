#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#define PI 3.14159265359
using namespace std; 


double X[10],Y[10];

bool isEqual(double x, double y)
{
	return 0.001 >= (double)abs(x - y ) ; 	
}

double dist(int A, int B)
{
	return (double)(X[A] -X[B])*(X[A]- X[B] ) + (double)(Y[A]- Y[B] )*(Y[A]-Y[B] );
}
main()
{
	freopen("inHEXA.txt","r",stdin);
	
	for(int i = 1; i <= 6 ;i ++)
		{
			cin >> X[i] >> Y[i];
		}

	double C[20];
	int n = 0;
	
	for(int i =2 ;i <= 6 ;i ++)
	{
		for(int j = 1 ; j< i ;j ++)
		{
			C[++n] = dist(i,j);
		}
	}
	
	sort(C+1, C+n+1);
	int CNT[4];
	CNT[0] = 0;	CNT[1] = 0;	CNT[2] = 0;	CNT[3] = 0;
	double tmp = -1;
	int i = 0;
	while(n > 0)
	{
		if(!isEqual(tmp,C[n]))
		{
			i ++;			
			tmp = C[n];			
		}		
		CNT[i]++;
		n--;		
	}
	
	if( (	CNT[1] != 3 ) || ( CNT[2] != 6 )||
		(   CNT[3] != 6)  || ( i !=3 	   ))
	cout << "NO";
	else cout << "YES";
}
