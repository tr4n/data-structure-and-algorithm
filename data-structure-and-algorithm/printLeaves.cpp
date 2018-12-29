void printLeaves(struct BNode* root)
{
	if(NULL == root  )
	{
		
		return ; 
	}
	
	if(root -> pFather == NULL && root -> left == NULL && root -> right == NULL)
	{
		return; 
	}
	
	if(root -> left == NULL && root -> right == NULL)
	{
		printf("%d ",root -> data);
		 
	}
	
	printLeaves(root -> left);
	printLeaves(root -> right);	
	
	
}
