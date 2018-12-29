package Problem;
import java.util.*;
public class CHUSO {

	public static Scanner in = new Scanner(System.in);
	
	public static int BinarySearch(int left, int right, long key)
	{
		int current = 0; 
		while(left <= right)
		{
			int mid = (left + right) >> 1; 
			if((long)(mid * (mid +1)) < ( key << 1))
			{
				current = mid; 
				left = mid +1; 
			}
			else
			{
				right = mid -1;
			}
		}
		
		return current; 
		
	}
	public static void main(String[] args) 
	{
		int T;
		long N,X; 
		
		T = in.nextInt();
		
		while(T-- > 0)
		{
			X = in.nextLong();
			
			int tmp = BinarySearch(1, (int)(Math.sqrt(2*X)),X);
			
			long ans = X - (long)(tmp * (tmp +1) >> 1);
			
			System.out.println(ans % 10);
			
			
			
			
		}
		
		
		

	}

}
