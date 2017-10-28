void reorganized(struct Node ** head)
{
	if( (*head) == NULL ||  (*head)-> pNext == NULL )
	{
		return;
	}
	

	struct Node *run  = *head; // The running pointer
  
	struct Node *stand = *head; // All the nodes where in the left of (stand) are non-negative 
	
	while(run  != NULL)
	{
		if(run -> data >= 0)
		{
			// Swap run -> data and  stand -> data
      int temp = 0 ;
			temp = run -> data; 
			run -> data = stand -> data; 
			stand -> data = temp; 
			
			// ok next 
			stand = stand -> pNext; 
		}
		
		run = run -> pNext; 		
		
	}
	
	
}
