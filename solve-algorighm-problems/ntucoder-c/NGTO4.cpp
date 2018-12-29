#include<iostream>
#include<algorithm>
using namespace std; 

int Prime[] = {2,3,5,7};
int A[1000003];



main()
{
	int N,T;
	A[1] = -1;
	A[2] = 1; 
	A[3] = 1;
	A[4] = 2; 
	A[5] = 1; 
	A[6] = 2;
	A[7] = 1;
	A[8] = 2; 
	A[9] = 2;
	A[10] = 2; 
	A[11] = 3;
	A[12] = 2;
	A[13] = 3;
	A[14] = 2;
	
	cin >> T; 
	while(T--)
	{
		cin >> N; 
		if(N <= 14)
		{
			cout << A[N] << endl;
			continue;
		}
		int cnt = N/7;
		int mod = N%7;
		if(mod == 0)
			cout << cnt << endl;
		else
		if(mod == 1 || mod == 2 || mod == 3 || mod == 5)
			cout << cnt +1 << endl;
		else 
			cout << cnt +2 << endl;
			
		
	} 
	
	

	
	
	
	
}
