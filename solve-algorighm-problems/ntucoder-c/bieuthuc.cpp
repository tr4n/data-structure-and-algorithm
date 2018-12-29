#include<iostream>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>

using namespace std; 

struct Node
{
	int data; 
	Node* pLeft;
	Node* pRight; 
	
};




Node* CreatNode(int x)
{
	Node* p = new Node();
	p -> data = x; 
	p -> pLeft = p->pRight = NULL;
	return p ;
}

Node* One = CreatNode(1);
Node* Zero = CreatNode(0);

Node* FindInsert(Node* root, int x)
{
	if(root == NULL)	
		return NULL;
		
	Node* p = root; 
	Node* f = p;
	while(p != NULL)
	{
		f = p ; 
		p -> data > x ? p = p -> pLeft : p = p -> pRight;
	/*
	 	if(p -> data >x)
	 		p = p -> pLeft; 
	 	else 
	 		p = p-> pRight;
	*/
	}
	return f; 
}


void  InsertNode(Node* &root, int x)
{
	Node* n = CreatNode(x);
	if(root == NULL)
	{
		root = n; 
		return  ; 
	}	
	else
	{
		Node* f = FindInsert(root, x);
		if(f != NULL)
		{
			
			f -> data >x ? f -> pLeft = n : f -> pRight = n;
		/*	
			
			if(f -> data >x)
				f -> pLeft = n ; 
			else 
				f -> pRight = n ;
		
		*/
		}
	}
	
}

void CreatTree(Node* &root, int A[], int n)
{
	for(int i = 1 ;i <= n ;i ++)
		InsertNode(root,A[i]);
}


int Depth(Node *root)
{
	Node* p = root;
	if(p == NULL) return 0;
	int LeftDepth =  Depth(p -> pLeft);
	int RightDepth = Depth(p -> pRight);
	return 1 + max(LeftDepth, RightDepth);
}


#define LNR LeftNodeRight
void LeftNodeRight (Node *root)
{
	if( root != NULL)
	{
		LNR(root -> pLeft);
		cout << root -> data << " ";
		LNR(root -> pRight);
	}
}

#define NLR NodeLeftRight
void NodeLeftRight (Node* root)
{
	if(root != NULL)
	{
		cout << root -> data << " ";
		NLR( root -> pLeft);
		NLR( root -> pRight);
	}
}

Node* SearchNode(Node* root, int x)
{
	if(root == NULL) 
		return NULL;
		
	if(root  -> data == x)
		 return root; 
		 
	if(root -> data > x) 
		return SearchNode(root -> pLeft, x);
	else
		return SearchNode(root -> pRight, x);
}

int DepthNode(Node* root, int x)
{
	if(root == NULL) return 0;
	
	
	Node* p = SearchNode(root, x);
	
	if(p != NULL) 
		return Depth(p);
	else
		return -1;
}

int RankNode(Node* root, int x)
{
	if(root == NULL) return 0;
	
}

main()
{
	freopen("bieuthuc.txt","r",stdin);
	
	string S, s = ""; 
	cin >> S; 
	/*
	 *	49 = 1
	 *	57 = 9
	*/	
	
	for(int i = 0; i< S.length() ;i ++){
		if(S[i] >57 || S[i]<49) s+= " ";
		s.push_back(S[i]);
	}
	
	cout << s << endl;
	
	
}







