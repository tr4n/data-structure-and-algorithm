#include<iostream>
#include<algorithm>

using namespace std; 
int Data[6];


main()
{
	int N; 
	cin >> N; 
	int A[N+3];
	for(int i =1 ;i <= 6 ;i ++)
		Data[i] = 0;
		
	for(int i =1 ;i <= N ;i ++)
	{
		cin >> A[i];
		Data[A[i]] ++;
	}
	
//	for(int i =1 ;i <= 4 ;i ++ )
//		cout << Data[i] << " ";
//	cout << endl;
	int res = 0; 
	
	res += Data[4];
	Data[4] = 0;
	
	if(Data[3] >= Data[1])
	{
		res += (Data[1]);
		Data[3] -= Data[1];
		res += Data[3];
		
		res += (Data[2]/2) + Data[2] % 2; 
	}
	else
	{
		res += Data[3];
		Data[1] -= Data[3];
		res += Data[2]/2;
		Data[2]%=2;
		
		if(Data[1] >= 2*Data[2])
		{
			res += Data[2];
			Data[1] -= (2*Data[2]);
			res += Data[1]/4 ; 
			if(Data[1] % 4 != 0)
				res ++;
		}
		else
			res ++;
		
	}
	
	cout << res << endl;
	
}
