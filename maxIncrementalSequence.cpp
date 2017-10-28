void maxIncrementalSequence(int A[], int n)
{
	/* 
	*	Gọi L[i] là độ dài của đoạn dãy con tăng lớn nhất kết thúc tại n
	*	
	*/
	int Length[n +3];
	Length[0] = 0;  // Nếu  
	
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
