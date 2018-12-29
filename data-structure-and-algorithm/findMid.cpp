Node findMid(Node *head)
{
	
	if(NULL == head -> pNext)	return *head; 
	
	Node *temp1 = head; // the pointer jump one step 
	Node *temp2 = head; // the pointer jump two steps  
	
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
//------------------------------------------------
Node findMid(Node *head)
{
	
	if(NULL == head -> pNext)	return *head; 
	
	Node *temp1 = head; // the pointer jump one step 
	Node *temp2 = head; // the pointer jump two steps  
	
	while( temp2 -> pNext != head && temp2 -> pNext -> pNext != head )
	{
		temp1 = temp1 -> pNext; 
		temp2 = temp2 -> pNext -> pNext; 
	}
	
	if(temp2 -> pNext == head)
		return *temp1 ; 
	else 	
		return *temp1->pNext ;
}
