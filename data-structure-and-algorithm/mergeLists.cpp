struct Node *mergeLists(struct Node *List1, struct Node *List2)
{
	if(NULL == List1 && NULL == List2)		return NULL;
	if(NULL == List1)				return List2;
	if(NULL == List2)				return List1;
	
	struct Node *p1 = List1; 
	struct Node *p2 = List2;
	struct Node *List = NULL;
	struct Node *last = NULL;
	
	
	while(p1 != NULL && p2 != NULL)
	{
		int data = min(p1 -> data, p2 -> data);
		// Insert Last  min 
		struct Node *p = new Node();
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
	
	/*
	* if(p1 != NULL) p3 = p1 ; else p3 = p2; 
	*/
	struct Node * p3 = (p1 != NULL) ? p1 : p2 ;
	
	
	while(p3 != NULL)
	{
		struct Node *p 		= new Node();
		p -> pNext	= NULL;
		p -> data 	= p3 -> data; 			
		last -> pNext 	= p; 
		last 		= p;
		
		p3 = p3 -> pNext;
	}
	
	return List; 	
	
}
