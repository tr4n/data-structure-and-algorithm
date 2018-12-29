#include<iostream>
#include<cstdio>
#include<cmath>
#define MAX 121998
#define oo 999999999
using namespace std; 

main()
{
	int A[MAX], N; 
	
	scanf("%d",&N);
	
	for(int i =1 ;i <= N ;i ++)
	{
	 scanf("%d",&A[i]);
	}
	
	/*
	* 	S[i] = sum of array from 1 to i 
	*	 ---> S[i] = S[i-1] + A[i];
	*	if there is not any element in array, Sum = 0 
	*	--> S[0] = 0;
	*	
	*/
	
	int S[MAX];	
	S[0] = 0   ;	
	for(int i =1 ;i <= N ;i ++)
	{
		S[i] = S[i-1] + A[i];
	}
	
	/*   
	*	Find the position i :   | S[N] - 2*S[i] | is min
	*	Initialize   Min = +oo , Pos = 0  to save max value and position
	*	At each i which  | S[N] - 2*S[i] | < Min , update Min = | S[N] - 2*S[i] | and Pos = i;
	*/
	
	int Min = oo,Pos = 0;
	for(int i =1 ;i <= N;i ++)
	{
		if(Min > abs( S[N] - 2*S[i]  ))
		{
			Min = abs( S[N] - 2*S[i] ) ; 
			Pos = i;			
		}	
	} 
	
	/*
	* 	Show answer
	*/
	for(int i =1 ;i <= N ;i ++ )
	{
	
		printf("%d",A[i]);
		if(i == Pos)  printf(" | "); 
		else printf(" ");
	}
	printf("\n %d | %d", S[Pos],S[N]- S[Pos]);

	// 	printf("%d %d",Pos,Max);
	
	
}
