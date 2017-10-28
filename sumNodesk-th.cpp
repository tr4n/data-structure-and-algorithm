struct Node
{
  int data; 
  struct Node* pLeft, *pRight, *pFather ; 
}

int sumNodes(struct Node *root, int k )
{
	if(root == NULL || k < 0)
	{
		return 0;
	}
	
	if(k == 0)
	{
		return root -> data; 
	}
	else
	{
		return sumNodes(root -> pLeft, k-1) + sumNodes(root -> pRight, k-1);
	}
	
}
// Trả về tổng tất cả các nút của cây nhị phân ở bậc thứ k
