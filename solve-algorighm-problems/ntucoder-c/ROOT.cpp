#include<iostream>
#include<cmath>

using namespace std; 

main()
{
	freopen("inROOT.txt","r",stdin);
	int T,N; 
	//cin >> T; 
	while(T--)
//	while(cin >> N)
	{
		cin >> N; 
		int tmp = 1;
		for(int i = 2; i*i <= N ; i ++ )
		{
			if(N%(i*i) == 0)
			{
				tmp *= i;
				N/=(i*i);
			}	
		}	
		
		cout << tmp << " " << N << endl; 
		
		
	}
	
}
