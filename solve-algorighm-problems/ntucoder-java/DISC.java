package Problem;
import java.util.*;
public class DISC {
	public static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		
		int N=1, M=1;
		
		N = in.nextInt();
		M = in.nextInt();
		
		int a = 0;
		boolean[] taken	= 	new boolean[N+3];		
		
		for(int i = 1 ;i <= N ;i ++)
		{
			taken[i] = false;
		}
		
		for(int i = M ;i >=  1 ;i --)
		{
			a = in.nextInt();
			if(!taken[a])
				System.out.print(a + " ");
			taken[a] = true;
		}
		
		for(int i =1 ;i <= N ;i ++)
		{
			if(!taken[i])
			{
				System.out.print(i + " ");
			}
		}

	}

}
