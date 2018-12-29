#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std; 

typedef pair<int,int> ii;
	ii A[5]; 

int  CHECK()
{
	if(A[2].first != A[3].first && A[2].second != A[3].second)
		return 0;
	if(A[2].first == A[3].first)
	{
		if(A[3].second == 0 || A[3].second == 9)
			return 0;
		else return 1;
	}
	
	if(A[2].second == A[3].second)
	{
		if(A[3].first == 0 || A[3].second == 8 )
			return 0;
		else return 2;
	}
	
}

int caculate()
{
	if(CHECK() == 1)
	{
		if(A[2].second > A[3].second)
		{
			if(A[1].first == A[2].first)
			{
				if(A[1].second < A[3].second -1)
					return 1;
				else if(A[1].second == A[3].second -1)
					return 0;
				else 
					return 3;
			}
			else
			{
				if(A[1].second <= A[3].second -1 )
					return 1; 
				else 
					return 2; 
			}
		}
		else 
		{
			if(A[1].first == A[2].first)
			{
				if(A[1].second > A[3].second -1)
					return 1;
				else if(A[1].second == A[3].second -1)
					return 0;
				else 
					return 3;
			}
			else
			{
				if(A[1].second >= A[3].second -1 )
					return 1; 
				else 
					return 2; 
			}
		}
	}
	else if(CHECK() == 2)
	{
		if(A[2].first > A[3].first)
		{
			if(A[1].second == A[2].second)
			{
				if(A[1].first < A[3].first -1)
					return 1;
				else if(A[1].first == A[3].first -1)
					return 0;
				else 
					return 3;
			}
			else
			{
				if(A[1].first <= A[3].first -1 )
					return 1; 
				else 
					return 2; 
			}
		}
		else 
		{
			if(A[1].second == A[2].second)
			{
				if(A[1].first > A[3].first -1)
					return 1;
				else if(A[1].first == A[3].first -1)
					return 0;
				else 
					return 3;
			}
			else
			{
				if(A[1].first >= A[3].first -1 )
					return 1; 
				else 
					return 2; 
			}
		}
	}
	else return -1;

}

main()
{

	for(int i =1 ;i <= 3 ;i ++)
	{
		cin >> A[i].first >> A[i].second;
	}
	
	if(CHECK())
		cout << caculate()+1;
	else 
		cout << -1 << endl;
	
}
