package Problem;

import java.util.*;
public class QN5 {
	public static Scanner in = new Scanner(System.in);
	
	public static long CircleNum(long N)
	{
		if( N <= 9) return N; 
		long res = N/10;
		long a=0,b = N%10; 
		
		while(N > 0)
		{
			a = N%10 ; 
			N /= 10;			
		};
		
		if(a <= b )
		{
			return res +9;
		}
		else
		{
			return res + 8;
		}
		
	}
	
	public static void main(String[] args) 
	{
		long L, R; 
		L = in.nextLong();
		R = in.nextLong();
		
		System.out.print(CircleNum(R) - CircleNum(L-1));
		
		

	}

}
