void printLeaves(struct BNode* root)
{
	if(root == NULL)	return; 	
	 
	struct BNode* STACK[1998];
	int TOP = 0;
	
	STACK[++TOP] = root;
	
	while(TOP > 0)
	{
		struct BNode*p = STACK[TOP --];			
		while(p != NULL)
		{
			if(p -> left == NULL && p -> right == NULL)
			{
				cout << p -> data << " ";
			}
			
			if(p -> right != NULL)
			{
				STACK[++TOP] = p -> right; 
			}
			
			p = p -> left; 
		}		
	}	
}
