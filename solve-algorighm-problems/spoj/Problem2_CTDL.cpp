#include<iostream>
#include<cstdio>
#include<cmath>

#define MAX 121998
#define oo 199999998
using namespace std;

main()
{
	int N, A[MAX]; 
	
	scanf("%d",&N);
	
	for(int i =1 ;i<= N ; i++) scanf("%d",&A[i]);
	
	/*
	*	B[j] is min value of elements from 1 to j
	*	---> B[j] = min( A[j], B[j-1] ) 
	*
	*	Find element j-th in array which  A[j] - B[j-1] is max 
	*
	*/
	
	
	int B[MAX],Max = -oo;
	int  Pos = 0,Sell,Buy;
	B[0] = oo;
	
	for(int j =1 ;j <= N ;j ++) 
		B[j] = min(A[j], B[j-1]); 
	
	for(int j =1 ; j<= N ; j++)
	{
		if(A[j] - B[j-1] > Max)
		{
			Max = A[j] - B[j-1];
			Pos = j; 
			Sell = A[j]; 
			Buy = B[j-1];	
		} 
	}
	
	/*
	*	Show answer
	*/
	
	printf("Buy - Sell :  %d %d",Buy,Sell);
	
}
