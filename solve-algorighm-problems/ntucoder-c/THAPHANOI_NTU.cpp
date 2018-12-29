#include<iostream>
using namespace std;

int N,K ;
int A,B,C; 
void HanoiTower(int N, int &A, int &B,  int& C)
{
	if(0 == K)
		return; 
		
	if ( 1 == N)
	{
		A--;
		B++; 		
		K--; 		
	}
	else
	{
		HanoiTower(N-1, A,C,B);
		HanoiTower(1,A,B,C);		
		HanoiTower(N-1,C,B,A);
		
	}
}

main()
{
	cin >> N >> K; 
	A = N ; B = C = 0;
	HanoiTower(N,A,B,C);
	cout << A << " " << B << " " << C << endl;
    
}
