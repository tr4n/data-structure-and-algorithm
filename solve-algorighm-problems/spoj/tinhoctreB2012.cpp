#include<iostream>
#include<cstdio>

#define ull unsigned long long
using namespace std; 

// 1 : up, 2: left ; 3 : down ; 4 : right;

	int line[8] = {0,1,2,6,5};
	int row [8] = {0,3,2,4};

int getData(int y)
{

	
	int tmp;
	switch(y)
	{
		
	
		case 1: 
			tmp = row[3];
			for(int i = 3;i>1 ;i --)
				row[i] = row[i-1];
			row[1] = tmp;
			swap(line[4],row[1]);
			
			break;
		case 2: 
			tmp = line[1];
			for(int i = 1;i < 4 ;i ++)
				line[i] = line[i+1];
			line[4] = tmp;
			break;
		case 3:
			tmp = row[1];
			for(int i = 1;i < 3 ;i ++)
				row[i] = row[i+1];
			row[3] = tmp;
			swap(line[4],row[3]);
			break;
		case 4:
			tmp = line[4];
			for(int i = 4 ;i >1 ;i --)
				line[i] = line[i-1];
			line[1] = tmp;
			break;
		
	}
	if(y ==1 || y == 3) 
	{
		line[2] = row[2];
	}
	else row[2] = line[2];
	return row[2];
	
}

void Print()
{
	cout << "  " << row[1] << endl;
	cout << line[1] << " " << line[2] << " " << line[3] << " " << line[4] << endl;
	cout << "  "  << row[3] << endl;
}

void Reset()
{
	line[1] = 1; line[2] = 2; line[3] = 6; line[4] = 5;
	row[1] = 3; row[2] = 2; row[3] =4;
}
ull Func(int N)
{
	Reset();
	ull Sum = 0;
	

	int A[N+3][N+3];
	int n = N ;
	int m = N ; 
	int p = 1;
	int cnt = 0;
	// 1 : up, 2: left ; 3 : down ; 4 : right;
	
	while(p<= n)
	{
		
		for(int i =p ;i <= n ;i ++)
		{
		//	A[p][i] = getData(2);
			int x = getData(2);
			A[p][i] = x;
			Sum += (ull)(x);
		}
		
		for(int i = p+1 ;i <= n ; i++)
		{
		//	A[i][n] = getData(3);
		int x = getData(3);
		A[i][n] = x;
		
			Sum += (ull)x;
		}
		
		for(int i = n-1;i >= p ;i --)
		{
		//	A[n][i] = getData(4);
	
			int x = getData(4);
				A[n][i] = x;
			Sum += (ull)(x);
		}
		for(int i = n-1 ;i >= p+1; i--)
		{
		//	A[i][p] = getData(1);
		int x = getData(1);
			A[i][p] = x; 
			Sum += (ull)x;
		}
		
		n--;p++;
		
	}
	/*
	int  a[7];
	for(int i = 1 ;i <= 7; i++) a[i] = 0;
	
	for(int i =1 ;i <= N ;i ++)
	{
		for(int j =1 ;j <= N ;j ++) 
		{
			cout << A[i][j] << " ";
			a[ A[i][j]] ++;
	//		Sum+= A[i][j] ; 
		}
		cout << endl;
	}
	*/

	cout << N << " Sum = " << Sum << endl;
	cout << "--" << endl;
	return (ull)Sum;
}

main()
{
	for(int i = 1 ;i <= 5 ;i ++) Func(i);
	
	Func(49);
	Func(50);
	Func(51);
	
	
}
