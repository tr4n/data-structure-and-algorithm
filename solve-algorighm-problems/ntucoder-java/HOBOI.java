package Problem;
import java.util.*;
public class HOBOI {

	public static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		
		int N = 1, M = 1; 
		String Row  = "";
		
		M = in.nextInt();
		N = in.nextInt();
		
		int S = 0;
		
		
		
		for(int i =1  ;i <= M ;i ++)
		{
			Row = in.next();
			
			boolean open = false;
			for(int j =0 ;j < N ;j ++)
			{
				if(Row.charAt(j) != '.' )
				{
					
					if(!open) 	open = true;
					else		
					{
						open = false;
						S++;
					}
				}
				
				if(open && Row.charAt(j) =='.')
				{
					S++;
				}
				
				
								
				
			}
			
		}
	
		System.out.println( S);
		
		
		

	}

}
