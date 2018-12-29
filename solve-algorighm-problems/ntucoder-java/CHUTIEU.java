package Problem;
import java.math.BigInteger;
import java.util.*;
import java.io.*;


public class CHUTIEU 
{
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) 
	{
				
		BigInteger	F[] 	= new BigInteger[503];	
		BigInteger	D[] 	= new BigInteger[503];
		BigInteger	U[]		= new BigInteger[503];
		
		// Huong Tru to Huong Tich first
		
		F[0] = new BigInteger("0"); 
		F[1] = new BigInteger("1"); 
		F[2] = new BigInteger("2"); 
		F[3] = new BigInteger("4"); 
		
		for(int i =4 ;i <= 500 ;i ++)
			F[i] = F[i-1].add(F[i-2].add(F[i-3]));
					
		// Mid -> Huong Tru
		U[0] = new BigInteger( "0"); 
		U[1] = new BigInteger("1"); 
		U[2] = new BigInteger("2");
			
		for(int i = 3 ;i <= 500 ;i ++ )
			U[i] =U[i-1].add(U[i-2]);			
					
		// Huong Tich -> Mid		
		 
		D[1] = new BigInteger("1") ; 
		D[2] = new BigInteger("2"); 
		D[3] = new BigInteger("4");
				
		for(int i = 4 ;i <= 500 ;i ++)
			 D[i] = (D[i-1].add(D[i-2].add(U[i-3])));		
		
		for(int i = 4 ;i <= 500; i ++)
			D[i] = D[i].subtract(U[i]);
				
		
		int m, n; 
		while(in.hasNext())
		{
			m = in.nextInt();
			n = in.nextInt();
			System.out.println(F[n].multiply(D[n].multiply(U[m].multiply(F[m]))));
			
		}
		

	}

}
