int countBNodes(struct BNode *root)
{
	if(root == NULL)
	{
		return 0; 
	}
	
	
	if(root -> left != NULL && root -> right != NULL)
	{
		return 1+ countBNodes(root -> left) + countBNodes(root -> right);
	}
	else
	{
		return countBNodes(root -> left) + countBNodes(root -> right);
	}
	
}
