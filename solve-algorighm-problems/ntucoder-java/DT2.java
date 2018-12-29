package Problem;
import java.util.*;

public class DT2 {

	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) 
	{
		
		int 		M,N;
		
		int[] X = new int [303];
		int[] Y = new int [303];
		M = in.nextInt();
		N = in.nextInt();
		
		int [][]	A = new int[103][103];
		int [][] 	F = new int[103][103];
		
		for(int i =1 ;i<= M ;i ++)
		{
			for(int j =1 ;j <= N ;j ++)
			{
				A[i][j] = in.nextInt();
			}
		}
		
		for(int i = 0 ;i <= M ;i ++)
		{
			F[i][0] = 0; 
		}
		
		for(int i = 0 ;i <= N ;i ++)
		{
			F[0][i] = 0;
		}
		
		for(int i =1 ;i<= M-1 ;i ++)
		{
			for(int j =1 ;j <= N ; j ++)
			{
				F[i][j] = Math.max(F[i-1][j], F[i][j-1]) + A[i][j];
				
			}
		}
		
		
				
		int i = M-1,j= N, res = -1;
		
		for( int k = N ;k >= 1 ;k --)
		{
			if(A[M][k] + F[M-1][k] > res)
			{
				res = A[M][k] + F[M-1][k];
				j =k;
				
			}
		}
		
		System.out.println(res);
		
		
		int n=2 ; 
		X[1] = M; Y[1] = j;
		
		
		while(i > 1 || j > 1)
		{
			
			X[n] = i;
			Y[n] = j;
			
			if(F[i][j] == F[i][j-1] + A[i][j])
			{
				j--;
			}
			else
			{				
				i--;
			}				
			n++;		
		}
		
		X[n] = 1; Y[n] = 1; 
		
		for( i = n ; i >= 1 ;i --)
		{
			System.out.println("("+X[i]+","+Y[i]+ ")");
		}
		
		
		

	}

}
