package Problem;
import java.util.*;
public class BIDA {
	
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) 
	{
		
		long n,m,y,x;
		long k ; 
		
		n = in.nextLong();
		m = in.nextLong();
		y = in.nextLong();
		x = in.nextLong();
		k = in.nextLong();
		
		x = (x+k-1)%(2*(m-1) )+1;
		y = (y+k-1)%(2*(n-1) )+1;
		
		if(x > m) x = 2*m - x; 
		if(y > n) y = 2*n - y; 
		
		System.out.println(y + " " + x);
		
		
		

	}

}
