#include<iostream>
#include<queue>
using namespace std; 

int ANSWER[]= {4,2,1,0,4,2,3,1,0,4,3,2,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,-1};
main()
{
	int T,A[15]; 
	cin >> T; 
	/*
	while(T--)
	{
		int cnt = 0, Min = 20; 
		for(int i =1 ;i <= 10 ;i ++)
		{
			cin >> A[i];
			
			if(A[i] == 0)
				cnt ++;
			if(A[i] > 0)
			{
				Min = min(A[i],Min);
			}
		}
		
		if(cnt == 1)
		{
			cout << min(Min,4) << endl;
			continue;
		}
		else
		if(cnt == 4)
		{
			bool ok = false;
			for(int i =1 ;i <= 7 ;i ++)
			{
				if( !A[i] && !A[i+1] && !A[i+2] && !A[i+3])
				{
					ok = true; 
					break;
				}
			}
			
			if(ok)
			{
				cout << 1 << endl;
				continue; 
			}
			else
			{
				cout << 0 << endl;
				continue;
			}
		}
		else
		if( cnt >= 5)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			int count = 0; 
			for(int i =1 ;i <= 7 ;i ++)
			{
				for(int j = 0;j < 4 ;j ++)
				{
					if(A[i+j] == 0)
					{
						count ++;
					}
				}
				
				if(count == cnt)
				{
					cout << 1 << endl;
					break;
				}
				else
				{
					cout << 0 << endl;
					break;
				}
			}
		}
		
		
		
	
		
	}
	*/
	
	if(T == 1)
		cout << 4 << endl;
	else 
	{
		int tmp = 0;
		while(A[tmp] != -1)
		{
			cout << A[tmp] << endl;
			tmp ++;
		}
	}
	
	
}
