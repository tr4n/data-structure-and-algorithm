#include<iostream>
#include<cstdio>
#include<cmath>

#define MAX 121998
#define oo 	199999998
using namespace std;


main()
{
	int A[MAX], N; 
	
	/***********************************************************
	*	Find elements in an array which sum of them is max 
	*	and any two elements are not contigous
	*	That array :  A[] = { a1,a2,...,ai,..,aN};
	*
	*
	************************************************************/
	cout << " Enter the number of elements: N = ";
	scanf("%d",&N); 
	cout << " Enter array of numbers : ";
	for(int i =1 ;i <= N ;i ++) 
		scanf("%d",&A[i]);
	
	int F[MAX], getMax = -oo;
	for(int i =1 ;i <= N ;i ++)
	{
		getMax = max(getMax, A[i]);
	}
	
	F[0] = 0;
	F[1] = max(0,A[1]);
	
	for(int i =2 ;i <= N ;i ++)
		F[i] = max(F[i-2] + A[i], F[i-1]);
	
	if(F[N] == 0) 
		printf("Sum = %d\n",getMax);
	else
	{
		printf("Sum = %d\n",F[N]);
		
		/***************************
		*	Trace 
		*	Show elements 
		*
		***************************/
		
		for(int i = N ;i >=2;)
		{
			if(F[i] == F[i-2] + A[i])
			{
				printf("A[%d] = %d \n",i,A[i]);
				i-=2;
			}
			else i--;
			
		}
		
		if(A[1]>0) printf("A[1] = %d",A[1]);
	}

	
}

