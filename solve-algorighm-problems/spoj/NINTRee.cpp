#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>

#define For(i,a,b) for(int i =a ;i <= b ;i ++)
using namespace std; 

int A[1998],B[1998],C[1998];

struct Node
{
	int data; 
	Node* pLeft; 
	Node* pRight; 
	
};

Node* CreatNode(int x)
{
	Node* p = new Node();
	p->data = x; 
	p->pLeft = p->pRight= NULL; 
	return p ; 
}

Node* FindInsert(Node* root, int x)
{
	if(root == NULL)
	{
		return NULL;
	}
	Node* p = root;
	Node* f = p; 
	while(p != NULL )
	{
		f = p;
		if( p->data > x)
		{
			p = p->pLeft;
		}
		else 
		{
			p = p->pRight;
		}
	}
	return f;
}

// Insert Node

int InsertNode( Node* &root, int x )
{
	Node* n = CreatNode(x);
	if( root == NULL )
	{
		root = n ; 
		
	}
	else 
	{
		Node* f = FindInsert(root, x);
		if(f!=NULL)
		{
			if(f->data >x)
			{
				f->pLeft = n ; 
			}
			else 
			{
				f->pRight = n ; 
			}
		}
	}
	
}

void CreatTree(Node* &root, int A[], int n )
{
	for(int i = 1; i<=n; i++)
	{
		InsertNode(root,A[i]);
	}
}

Node* SearchNode_Re(Node* root, int x)
{
	if( root == NULL)
		return NULL;
	
	if(root->data==x)
	{
		
		return root;
	}
	
	if(root->data >x)
	{
		SearchNode_Re(root->pLeft,x);
	}
	else
	{
		SearchNode_Re(root->pRight,x);
	}
	
}

#define NLR NodeLeftRight
void NodeLeftRight (Node* root)
{
	if(root != NULL)
	{
		cout << " " << root->data ;
		NLR(root -> pLeft);			
		NLR(root -> pRight);
	}	
}

#define LNR LeftNodeRight
void LeftNodeRight(Node* root)
{
	if(root != NULL)
	{
		LNR(root -> pLeft);
		cout << " " << root -> data;
		LNR(root -> pRight);
	}
}

#define RNL RightNodeLeft
void RightNodeLeft(Node* root )
{
	if(root != NULL)
	{
		RNL(root -> pRight);
		cout << " " << root -> data; 
		RNL(root -> pLeft);
	}
}

#define LRN LeftRightNode
void LeftRightNode(Node* root)
{
	if(root != NULL)
	{
		LRN(root -> pLeft);
		LRN(root -> pRight);
		cout << " " << root -> data;
	}


}
main()
{
	freopen("inBINTREE.txt","r",stdin);
	Node* root = NULL; 
	int N; 
	cin >> N; 

	For(i,1,N) cin >> A[i];
	For(i,1,N) cin >> B[i];
	For(i,1,N) C[i] = i;
	CreatTree(root,C,N);
	NLR(root);
	cout << endl;
	
	LRN(root); 
	cout << endl;
	
	int x; 
	while(scanf("%d",&x)!= EOF ) 
	cout << SearchNode_Re(root,x) <<endl;
	
	
}
















