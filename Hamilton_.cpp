#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define BASE (V + 1)
#define ull unsigned long long
#define MOD 1000000007LL
using namespace std; 

typedef pair <int, int> ii ;

int V, E; 
ii Edge[100];
int Result[100];
int Vertex[100];
int countVertex = 0; 
int number = 0, numberZero = 0, numberHash = 0; 
ull hash[100], HASH = 0;


void Initgraph()
{
	int cnt = 0; 
	cin >> V; 
	E = 0; 
	for(int i = 1;i <= V ;i ++)
	{
		for(int j = 1;j <= V ;j ++)
		{
			int a; 
			cin >> a; 
			if(i < j && a == 1)
			{
				
				Edge[++E] = ii(i,j);	
			}
		}
	}
	for(int i = 1;i <= V ;i ++)
	{
		Vertex[i]  = 0; 
	}
}

void InitGraph()
{
	cin >> V >> E; 	
	for(int i = 1;i <= E;i ++)
	{
		int p,q; 
		cin >> p >> q; 
		if(p > q) swap(p,q);
		Edge[i] = ii(p,q);
	}
	for(int i = 0 ;i <= V ;i ++)
	{
		Vertex[i] = 0;
	}	
}

bool checkHash(){
	HASH = 0; 
	for(int i =1  ;i <= V ;i ++)
		if(Vertex[i] == 2)
			HASH = ((HASH*BASE)%MOD + i)%MOD;		
	
	for(int i = 1; i <= numberHash ;i ++ )
		if(hash[i] == HASH )		
			return false; 	

	hash[++numberHash] = HASH; 	
	return true; 
}

void Print()
{		
	for(int i = 1;i <= V ;i ++)
		if(Vertex[i] == 1)
			return; 
		
		
	if(!checkHash())	return ; 	
	
	for(int i = 1;i <= V ;i ++)
		if(Vertex[i] == 2)
			cout << i <<  " ";	
	 
	cout << endl;
	number ++ ; 
}

bool check(int k,  int pos){
	if(k == 0){
		if(numberZero >= E - 3)
			return false; 
		else
			return true; 
	}	 	
	if (Vertex[ Edge[pos].first ] == 2 ||  Vertex[ Edge[pos].second ] == 2)
		return false; 		
	return true; 
}

void Action(int i,  int pos, int p )
{
	if(p == 0){
		if(i == 0)
			numberZero ++;
		else{
			Vertex[Edge[pos].first] ++ ; 
			Vertex[Edge[pos].second] ++ ;	
		}		
	}else{
		if(i == 0)
			numberZero --;
		else{
			Vertex[Edge[pos].first] -- ; 
			Vertex[Edge[pos].second] -- ;
		}	
	}
}



void BackTrack(int pos)
{
	if(pos == E + 1)
	{
		Print();
		return; 
	}
	
	for(int i = 0 ;i <2 ;i ++)
	{
		
		if(check(i,pos))
		{		
			Action(i,pos,0);
			Result[pos] = i ; 
			BackTrack(pos + 1);
			Action(i,pos,1);		
		}
	}
}



main()
{
	freopen("initGraph.txt","r",stdin);
	Initgraph();
	
	
	BackTrack(1);
	cout << number << endl;
	
}
 
