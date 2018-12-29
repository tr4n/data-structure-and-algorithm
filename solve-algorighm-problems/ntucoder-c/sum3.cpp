#include<iostream>
#include<algorithm>
using namespace std; 

typedef pair <int, int> ii;
bool Check[121998];
int A[121998];

ii Search (int A[], int begin, int end, int value)
{
	int i = begin, j = end;
	
	while(i < j)
	{
		if(A[i] + A[j] == value) return ii(A[i],A[j]);
		else
		if(A[i] + A[j] > value) 
			j--;
		else 
			i ++;
	}
	
	return  ii(-1,-1);
}

void QuickSort(int A[], int x, int y)
{
	int k = x,v  = A[y] ; 
	
	for(int i =x ;i < y ; i ++)
	{
		if(A[i]<=v)
		{
			swap(A[i],A[k]);
			k++;
		}
	}
	swap(A[y],A[k]);
	
	if(x<k) QuickSort(A,x,k-1);
	if(k<y) QuickSort(A,k,y);
	
	
}
	
void Init(int N)
{
	for(int i =1 ;i <= N ;i ++)
		{
			bool ck = false;
			while(!ck)
			{
				int x = rand()%(2*N) - N;
				if(!Check[x])
				{
					Check[x] = true;
					A[i] = x;
					ck = true;
				}
			}
		}
}
	


main()
{
//	freopen("inSum3.txt","r",stdin);
//	freopen("outSum3.txt","w",stdin);
	
	int N,M; 
	
	
	cin >> N >> M; 
	// Input
	Init(N);
	
	
	for(int i =1 ;i <= N ;i ++) 
		cout << A[i] << " ";
	cout << endl;
	
	// Process
	sort(A+1, A+N+1);	
	
	for(int i =1 ;i <= N ;i ++)
	{
		ii p = Search(A,i+1,N,M - A[i]);
		if(p != ii(-1,-1))
		{
			
			cout << M 		<< " = " <<
					A[i]  	<< " + " << 
					p.first << " + " << 
					p.second<<  endl;
		}
	}
	
	
}
