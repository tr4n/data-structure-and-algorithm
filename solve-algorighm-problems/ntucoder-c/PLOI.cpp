#include<iostream>
#include<queue>
using namespace std; 

main()
{
	queue <int> q;
	int M[20];
	int N,a; 
	cin >> N;
	
	for(int i =1 ;i <= 11 ;i ++)
	{
		M[i] = 0;
		
	}
		 
	for(int i =1 ;i <= N ;i ++)
	{
		cin >> a; 
		
		M[a]++;
		if(M[a] == 3)
		{
			q.push(a);
			M[a] = 0;
			
		}
			
	}
	
	cout << q.size() << endl;
	while(q.size())
	{
		cout << q.front() << " ";
		q.pop();
	}
		
	
}
