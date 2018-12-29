void splitLinkedList(struct NODE **head, struct NODE **secondhead) 
{
	struct NODE *run = *head, *pPosition= *head;
	int SumOfHead = 0, SumToElement = 0;
	int Maxinum = -1; 
	while(run != NULL){
		SumOfHead += run -> data; 
		run = run -> pNext; 
	}	
	
	run = *head;
	while(run != NULL){
		SumToElement += run -> data; 
		int Delta = SumOfHead >2*SumToElement ? SumOfHead-2*SumToElement : 2*SumToElement - SumOfHead; 
		if(Delta > Maxinum){
			Maxinum = Delta;
			pPosition = run; 
		}
		
		run = run -> pNext; 
			
	}
	
	*secondhead = pPosition-> pNext; 
	pPosition-> pNext = NULL;  	
	
}
