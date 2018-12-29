/*
 * We have an integer list which each pair of consecutive elements has a 
 * discrete value of -1 or +1, and an integer x. Let's introduce the 
 * algorithm to find the position of x in the list as quickly as ( < O(n) )
 * 
 */

import java.util.*;
public class findnum {
	public static Scanner in = new Scanner(System.in);
	
	public static int Search(int A[], int left, int right, int key)
	{
		int position = left ; 
		while(position <= right)
		{
			if(A[position] == key)
					return position;						
			position += Math.abs(key - A[position]);		
		}		
		return -1;
		
	}
	
	public static void main(String[] args) {
		
		int 	N = 0; 
		int [] 	Array = new int[103];
		int 	key = 1;
		
		N = in.nextInt();		
		
			
		for(int i =0 ;i < N ;i ++)
		{
			Array[i] = in.nextInt();
			
		}		
		key = in.nextInt();
		
		int position = Search (Array, 0, N-1 , key);
		
		if(position > 0)
		{
			System.out.println(position);
		}		
		else
		{
			System.out.println(" Can not find " + key +" in list " );
		}
		
	
		
	
		
					

	}

}
