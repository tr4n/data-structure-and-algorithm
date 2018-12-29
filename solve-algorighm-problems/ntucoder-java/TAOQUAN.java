package Problem;
import java.util.*;
public class TAOQUAN {

	public static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		int N,M,K; 
		
		N = in.nextInt();
		M = in.nextInt();
		K = in.nextInt();
		
		System.out.print(Math.min((int) ((N+M-K)/3), Math.min(M, (int)(N/2))));
		
	}

}
