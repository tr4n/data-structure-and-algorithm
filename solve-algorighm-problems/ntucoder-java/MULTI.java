package Problem;
import java.util.*;

public class MULTI {
	public static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		int 	N,M,L=1,R=1,A;
		
		N = in.nextInt();
		M = in.nextInt();
		
		//int[] 	positive = new int[N+3];
		int[]	negative = new int[N+3];
		int[] 	zero	 = new int[N+3];
		
		//positive[0] = 
		negative[0] = zero[0] = 0;
		
		for(int i =1 ;i <= N ;i ++)
		{
			A = in.nextInt();
			negative[i] = negative[i-1];
			zero[i] = zero[i-1];
			if(A < 0)
				negative[i]++;
			else
				if(A == 0)
					zero[i]  ++;
						
		}
		
		for(int i = 1 ;i <= M ;i ++)
		{
			L = in.nextInt();
			R = in.nextInt();
			
			int ZERO = zero[R] - zero[L-1];
			int Negative = negative[R] - negative[L-1];
			
			if(ZERO > 0)
			{
				System.out.println(0);
			}
			else
			if(Negative % 2 != 0)
			{
				System.out.println('-');
			}
			else
				System.out.println('+');
			
			
		}
		
		
		
		
		
		
		
		
	}
	
	
}
