package Problem;
import java.util.*;
public class QUACAU {
	
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) 
	{
		int N; 
		int[] 	A = new int[123];
		int[] 	F = new int[123];
		N = in.nextInt();
		
		for(int  i = 1; i <= N ;i ++)
		{
			A[i] = in.nextInt();
		}
		
		Arrays.sort(A,1,N+1);
		
		
		F[0] = 0;
		F[1] = A[1];
		F[2] = A[2];
		
		for(int i = 3 ;i <= N ;i ++)
		{
			F[i] = Math.min(F[i-1] + A[i] + A[1], F[i-2] + A[1] + A[i] + 2*A[2]);			
		}
		
		System.out.println(F[N]);
		
		
		

	}

}
