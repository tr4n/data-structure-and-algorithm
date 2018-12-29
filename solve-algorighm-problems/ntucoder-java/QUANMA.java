package Problem;
import java.util.*;
public class QUANMA {
	public static Scanner in = new Scanner(System.in);
	
	
	
	
public static void main(String[] args)
	{
		int N = 0; 
		int[] A = new int[111111];
		
		N = in.nextInt();
		
		for(int i =1 ;i <= N ;i ++)
		{
			A[i] = in.nextInt();
		}
		
		int numberMax = -1,cnt = 0;
		int top = -1; 
		
		for(int i = 1;i <= N ;i ++)
		{
			if(A[i] != top)
			{
				
				cnt = 0; 
				top = A[i];
			}
			
			cnt ++;	
			numberMax = Math.max(cnt, numberMax);
		}
		
		System.out.println(N - numberMax);
		
	}
	
	
}
