#include<iostream>
#include<algorithm>
using namespace std; 


struct NODE
{
	int data; 
	struct NODE *pNext; 
};


typedef struct NODE Node; 

Node* head = NULL; 



Node *CreatNode(int x)
{
	Node *p = new NODE();
	p ->  data = x;
	p -> pNext = NULL;
	
	return p ;  
	
}

void InsertFirst(Node *&head, int data)
{
	Node *p = new NODE();
	
	p -> data = data; 
	
	if(NULL == head)
		p -> pNext = NULL; 
	
	else
		p -> pNext = head ; 
	
	head = p ; 
	
}


void InsertLast(Node*&head, int data)
{
	struct NODE * p = new NODE();

		
	p -> data = data; 
	p -> pNext = NULL;
	
	if(head == NULL)
	{	
		head = p ; 
		return; 
	}
	
	struct NODE *last = head;
	while(last -> pNext != NULL)
	{
		last = last -> pNext; 
	}	

	last -> pNext = p ;
	last = p ;	
	
}
void CreatList(Node *&head, int A[], int N)
{
	for(int i =1 ;i <= N ;i ++)
		InsertLast(head,A[i]);
	
}

void PrintList(Node *head)
{
	if(head == NULL)
		return;
	cout << head -> data << " ";
	PrintList(head -> pNext);
	
	
}

Node findMid(Node *head)
{
	
	if(NULL == head -> pNext)	return *head; 
	
	Node *temp1 = head;
	Node *temp2 = head; 
	
	while( temp2 -> pNext != NULL && temp2 -> pNext -> pNext != NULL )
	{
		temp1 = temp1 -> pNext; 
		temp2 = temp2 -> pNext -> pNext; 
	}
	
	if(temp2 -> pNext == NULL)
		return *temp1 ; 
	else 	
		return *temp1->pNext ;
}



Node *findPos(Node *head)
{
	int sum = 0, Min = 999999;
	Node *pos = head; 
	
	if(head == NULL)
		return NULL;
		
	Node *p = head; 
	int Sum = 0; 
	while(p  != NULL)
	{
		Sum += p -> data; 
		p = p-> pNext; 
	};
	
	
	p = head; 
	
	while(p != NULL)
	{
		sum += p -> data; 
		if( abs(Sum - 2*sum) <= Min)
		{
			Min = abs(Sum - 2*sum);
			pos = p ; 
		}
		p = p-> pNext; 
		
	};
	
	if(Min == 999999)
		return NULL;
	
	return pos; 
	
	 
}



void reorganized(struct NODE ** head)
{
	if( (*head) == NULL ||  (*head)-> pNext == NULL )
	{
		return;
	}
	
	int data = 0; 
	struct NODE *run  = *head;
	struct NODE *stand = *head;
	
	while(run  != NULL)
	{
		if(run -> data >= 0)
		{
			// Swap
			data = run -> data; 
			run -> data = stand -> data; 
			stand -> data = data; 
			
			// ok next 
			stand = stand -> pNext; 
		}
		
		run = run -> pNext; 
		
		
	}
	
	
}

struct NODE *mergeLists(struct NODE *List1, struct NODE *List2)
{
	if(NULL == List1 && NULL == List2)		return NULL;
	if(NULL == List1)				return List2;
	if(NULL == List2)				return List1;
	
	struct NODE *p1 = List1; 
	struct NODE *p2 = List2;
	struct NODE *List = NULL;
	struct NODE *last = NULL;
	
	
	while(p1 != NULL && p2 != NULL)
	{
		int data = min(p1 -> data, p2 -> data);
		// Insert Last  min 
		Node *p = new NODE();
		p -> pNext = NULL;
		p -> data =  data; 
		
		if(List == NULL)
		{
			List = p ; 
			last = List;
		}
		else
		{
			last -> pNext = p; 
			last = p;
		}
		// next pointer 
		if(data == p1 -> data)
		{
			p1 = p1 -> pNext;
		}
		else
		{
			p2 = p2 -> pNext;	
		}		
	}
	
	//
	if(p1 != NULL)
	{
		while(p1 != NULL)
		{
			Node *p 	= new NODE();
			
			p -> pNext 	= NULL;
			p -> data 	= p1 -> data; 			
			last -> pNext 	= p; 
			last 		= p;
		
			p1 = p1 -> pNext; 
		}
		
	}
	else if(p2 != NULL)
	{
		while(p2 != NULL)
		{
			Node *p = new NODE();
			p -> pNext = NULL;
			p -> data = p2 -> data; 
			last -> pNext = p; 
			last = p;
		
			p2 = p2 -> pNext; 	
		}
	}
	
	return List; 	
	
}
void splitLinkedList(struct NODE **head, struct NODE **secondhead) 
{
		
	
}

main()
{
	Node* head = NULL; 
	Node *list1 = NULL, *list2 = NULL;
	
	int N; 
	cin >> N; 
	int A[N+3],B[N+3];
	for(int i =1 ;i<= N ;i ++)
		cin >> A[i];
	for(int i = 1; i<= N ;i ++)
		cin >> B[i];
	sort(A+1,A+N+1);
	sort(B+1,B+N+1);
	
	CreatList(list1, A,N);
	CreatList(list2,B,N);
	cout << " List 1: " ; 	PrintList(list1); cout << endl;
	cout << " List 2: " ; 	PrintList(list2); cout << endl;
	cout << endl; 
//	cout << findMid(head).data << endl;
	
	Node *list3 = mergeLists(list1, list2); 
	cout << " merge : ";
	PrintList(list3);
	
	
	
	
}
