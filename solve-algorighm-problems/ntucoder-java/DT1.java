package Problem;
import java.util.*;

public class DT1 {
	public static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int			cnt = 0;
		int 		k=1,N;
		int[] 		Number = new int[543210];
		
		N = in.nextInt();
		Number[0] = 0; 
		
		for(int i =1 ;i <= 1000 ;i ++)
		{
			cnt = 0;
			for(int j = 1 ;;j ++)
			{
				if(j*i > Number[k-1])
				{
					Number[k] = i*j;
					k++;
					cnt ++;
				}
				
				if(cnt == i)
					break;
			}
			
		}
		
		System.out.println(Number[N]);
			

	}

}
