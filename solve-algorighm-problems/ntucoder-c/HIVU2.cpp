#include<iostream>
#define ull unsigned long long
using namespace std; 


main()
{
	ull cnt = 0;
	int N, M; 
	cin >> N >> M;
	for(int i = 1 ;i <= min(M,N) ;i +=2)
		cnt += (ull)i*(M-i+1)*(N-i+1);
	 
	cout << (ull)cnt; 
}
