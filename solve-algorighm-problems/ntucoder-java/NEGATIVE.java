package Problem;

import java.util.Scanner;

public class NEGATIVE {
	public static Scanner in = new Scanner(System.in);
	
	public static long P=0,N,n=0; 
	
	public static long negative(long n)
	{
		
		
		if(n == 0 )
				return P ; 
		
		negative(n /2);
		
		if(n%2 == 0) 
			P = 2*P + 1;
		else
			P *= 2;
		
		return P; 
		
	}

	public static void main(String[] args) {
		
		int T; 
		T = in.nextInt();
		
		for(int t = 1 ; t <= T ; t ++)
		{
			P = 0;
			
			N = in.nextLong();
			
			n = N; 
			if(n == 0)
				System.out.print(1);
			else
				System.out.println(negative(n));
		}
		

	}

}
