package Problem;
import java.util.*;

public class QUEUE {
	public static Scanner in = new Scanner(System.in);
	public static int N;
	public static int getItself(int a, int b)
	{
		return a; 
	}
	
	
	public static void QuickSort(int A[], int begin, int end)
	{
		int mid = A[(int)((begin + end)>>1)];
		int i = begin, j = end; 
		
		while(i < j)
		{
			while(A[i] < mid) i ++;
			while(A[j] > mid) j --;
			
			if( i <= j)
			{
				if(i != j)
				{
					System.out.println(i + " " + j );					
					
				}
				
				int tmp  = A[i] ; A[i] = A[j] ;A[j]  = tmp;
				
				
				i++;
				j--;
				
			}			
		};
		
		if(begin < j) 	QuickSort(A,begin,j);
		if(i < end) 	QuickSort(A,i,end);
		
		
	}
	
	
	public static void main(String[] args)
	{
		N = in.nextInt();
		int[]	A = new int[N+3];
		
		for(int i =1 ;i <= N ;i ++)
		{
			A[i] = in.nextInt();
		}
		
		QuickSort(A,1,N);
		
		
		
		
		
	}

}
