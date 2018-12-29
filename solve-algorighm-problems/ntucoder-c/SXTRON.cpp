#include<iostream>
using namespace std; 

main()
{
	int N,M; 
	cin >> N>> M; 
	
	int A[N+3],B[M+3];
	
	for(int i =1 ;i <= N ;i ++)
		cin >> A[i];
	for(int j =1 ;j<= M ;j ++)
		cin >> B[j];

	int k = 0, i = 1, j = 1; 
	
	while(i <= N && j <= M)
	{
	
		
		if(A[i] < B[j])
		{
			cout << "b" << i << " ";
			i ++ ; 
			
		}
		else 
		{
			cout << "c" << j << " ";
			j ++ ; 
		}
		
	}
	
	if(i <= N)
		for(k = i ; k <= N ;k ++)
			cout << "b" << k << " ";
	if(j <= M)
		for(k = j ; k <= M ; k ++)
			cout << "c" << k << " ";

}
