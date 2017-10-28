void maxIncrementalSequence(int A[], int n)
{
	int L[n +3];
	L[0] = 0; 
	
	for(int i =1 ;i <= n ;i ++)
	{
		L[i] = 1; 
		for(int j =1 ;j < i ;j ++)
		{
			if(A[i] > A[j]&& L[i] < L[j] + 1) 
			{
				L[i] = L[j] + 1;
			}
		}
		
	}
	
	printf(" max Incremental Sequence : %d ", L[n] );
	
  // Bài này dùng Quy Hoạch Động, độ phức tạp là O(n^2)
	
}
