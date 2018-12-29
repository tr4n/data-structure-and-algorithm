#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

#define MAX 500
#define _p(i,j) (i-1)*m + j

using namespace std; 

typedef pair <int, int> ii; 

const int Dx[] = {0, 1, 0, -1, 0};
const int Dy[] = {0, 0, 1, 0, -1};  
// Vtr : 0 -> nothing || 1 -> Right || 2 -> Up || 3 -> Left || 4 -> Down

 struct Point
{
	int x; 
	int y; 
	int vtr; 
} ;

Point getPoint(Point &Node,int x, int y, int vtr)
{
	Node.x = x; 
	Node.y = y; 
	Node.vtr = vtr;
	return Node;
}

Point gPoint(Point &Node, Point Node2)
{
	Node.x = Node2.x; 
	Node.y = Node2.y; 
	Node.vtr = Node2.vtr;
	return Node;
}




int a[MAX][MAX];
int n, m ; 
int Xd, Yd ; 
bool Free[23][23][6];
bool Found = false; 

Point Trace[23][23][6];
Point Start,Target ;

void InitGraph()
{
	cin >> n >> m; 
	for(int i =1 ;i <= n ;i ++)
	{
		for(int j = 1 ;j <= m ;j ++)
		{
			cin >> a[i][j];
		}
	}
	cin >> Xd >> Yd; 
	
	for(int i = 1 ;i <= n ;i ++)
		for(int j =1 ;j <= m ;j ++)
			for(int k = 0;k <= 4 ;k ++)
				{
					Free[i][j][k] = true;
				}
	
	getPoint(Start,1,1,0);
	gPoint(Trace[1][2][1],Start);
	gPoint(Trace[2][1][4],Start);
	getPoint(Target,Xd,Yd,0);
	
	
}

bool Check(Point u, int i)
{
	
	if(u.y == m && i == 1) return false;
	if(u.y == 1 && i == 3) return false;
	if(u.x == 1 && i == 2) return false; 
	if(u.x == n && i == 4) return false;
	
	if(u.vtr == 1 && (i == 3 || i == 4)) return false;
	if(u.vtr == 2 && (i == 1 || i == 4)) return false; 
	if(u.vtr == 3 && (i == 1 || i == 2)) return false;
	if(u.vtr == 4 && (i == 2 || i == 3)) return false;
	
	if(a[u.x + Dx[i]][u.y + Dy[i]] == 1) return false;
		
	return Free[u.x + Dx[i]][u.y + Dy[i]][i];
		
	
	
	
}



void Visit(Point u)
{
	
	if(u.x == Xd && u.y == Yd)
	{
		Trace[Xd][Yd][0] = Trace[u.x][u.y][u.vtr];
		Found = true;
		return;
	}
	
	Free[u.x][u.y][u.vtr] = false; 
	
	
		
		for(int i = 1 ;i <= 4 ;i ++)
		{
			if(Check(u,i) )
			{
				Point v ; 
				getPoint(v,u.x + Dx[i], u.y + Dy[i],i);
				Trace[v.x][v.y][v.vtr] = u; 
				Visit(v);
			}
				
		}
		
	
	
}

main()
{
	freopen("_inROBOT4.txt","r",stdin);
	InitGraph();
	Visit(Start);
	
	Point v = Target; 
	
	vector <ii> q;
	
	if(Xd == 1)
	{
		cout << m << endl;
		for(int i = 1 ;i <= m ;i ++)
			cout << 1 << " " << i << endl;
	}
	else if(Yd == 1)
	{
		for(int i =1 ;i <= n ;i ++)
			cout << i << " " << 1 << endl;
	}
	else
	if(Found)
	{
		do
		{
			q.push_back(ii(v.x,v.y));
			v = Trace[v.x][v.y][v.vtr];
			
		}while(v.x != 1 || v.y != 1);
		
		cout << q.size()+1 << endl;
		cout << 1 << " " << 1 << endl;
		while(!q.empty())
		{
			cout << q.back().first <<  " " << q.back().second << endl;
			q.pop_back();
		}
	}
	else cout << 0 << endl;
	
	
	
}
  
