#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define BASE (numberVertex + 1)
#define ull unsigned long long
#define MOD 1000000007LL
using namespace std; 

typedef pair <int, int> ii ;

int numberVertex, numberEdge; 
ii Edge[100];
int Result[100];
int Vertex[100];
int number = 0, numberZero = 0, numberHash = 0; 
ull hash[100], HASH = 0;


void Initgraph()
{
	int cnt = 0; 
	cin >> numberVertex; 
	numberEdge= 0; 
	for(int i = 1;i <= numberVertex;i ++){
		for(int j = 1;j <= numberVertex;j ++){
			
			int a; 
			cin >> a; 
			if(i < j && a == 1){				
				Edge[++numberEdge] = ii(i,j);	
			}
		}
	}
	for(int i = 1;i <= numberVertex;i ++){
		
		Vertex[i]  = 0; 
	}
}

void InitGraph()
{
	cin >> numberVertex>> numberEdge; 	
	for(int i = 1;i <= numberEdge;i ++)
	{
		int p,q; 
		cin >> p >> q; 
		if(p > q) swap(p,q);
		Edge[i] = ii(p,q);
	}
	for(int i = 0 ;i <= numberVertex;i ++)
	{
		Vertex[i] = 0;
	}	
}

bool checkDecreaseHash(){
	HASH = 0; 
	for(int i =1  ;i <= numberVertex;i ++)
		if(Vertex[i] == 2)
			HASH = ((HASH*BASE)%MOD + i)%MOD;		
	
	for(int i = 1; i <= numberHash ;i ++ )
		if(hash[i] == HASH )		
			return false;

	hash[++numberHash] = HASH; 	
	return true; 
}

void Process()
{		
	for(int i = 1;i <= numberVertex;i ++)
		if(Vertex[i] == 1)
			return; 		
	if(!checkDecreaseHash()) return ; 	
	
	for(int i = 1;i <= numberVertex;i ++)
		if(Vertex[i] == 2)
			cout << i <<  " ";	
	 
	cout << endl;
	number ++ ; 
}

bool checkDecrease(int i,  int position){
	if(i == 0){
		if(numberZero >= numberEdge- 3)
			return false;
		else
			return true; 
	}	 	
	if (Vertex[ Edge[position].first ] == 2 ||  Vertex[ Edge[position].second ] == 2)
		return false;	
	return true; 
}

void Decrease(int i,  int position, int mode)
{
	if(mode== 0){
		if(i == 0)
			numberZero ++;
		else{
			Vertex[Edge[position].first] ++ ; 
			Vertex[Edge[position].second] ++ ;	
		}		
	}else{
		if(i == 0)
			numberZero --;
		else{
			Vertex[Edge[position].first] -- ; 
			Vertex[Edge[position].second] -- ;
		}	
	}
}



void BackTrack(int position)
{
	if(position == numberEdge+ 1)
	{
		Process();
		return; 
	}
	
	for(int i = 0 ;i <2 ;i ++)
	{		
		if(!checkDecrease(i,position)) continue ;
			
		Decrease(i,position,0);
		Result[position] = i ; 
		BackTrack(position + 1);
		Decrease(i,position,1);		
		
	}
}



main()
{
	freopen("initGraph.txt","r",stdin);
	Initgraph();
	
	BackTrack(1);
	cout << number << endl;
	
}
 
