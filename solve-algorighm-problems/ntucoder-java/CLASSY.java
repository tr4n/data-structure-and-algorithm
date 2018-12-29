package Problem;
import java.util.*;

public class CLASSY {
	public class pair{
		int first; 
		int second;
	}
	public static Scanner in = new Scanner(System.in);
	public static int MAX = -1;
	public static int[] number = new int[103];
	public static int[] value  = new int[103];		
	public static int []	Key	= new int[102];
	
	public static int getItself(int a, int b)
	{
		return a; 
	}
	
	public static void QuickSort(int A[], int left , int right)
	{
		int i = left, j = right; 
		int mid = A[(int)((left + right)>>1)];
		
		while(i < j)
		{
			while(A[i] > mid) i ++;
			while(A[j] < mid) j --;
			
			if(i <= j)
			{
				if(i < j)
				{
					A[i] = getItself(A[j], A[j] = A[i]);
					Key[i] = getItself(Key[j],Key[j] = Key[i]);
				}					
					i++;
					j--;			
			}		
		}
		
		if(left < j) QuickSort(A,left, j);
		if(i < right) QuickSort(A,i,right);
	}
	
	
	
	
	public static void caculateClass(String S, int k)
	{
		S = "-" + S;
		int cnt = 0;
		int Num = 0;
		for(int i = S.length()-2 ; i>=0;i --)
		{
			char ch = S.charAt(i+1);
			if(S.charAt(i) == '-')
			{
				cnt ++;
				
				if( ch == 'u') {
					Num = Num*10 + 3;
				}
				else
					if(ch == 'm')
					{
						Num = Num*10 + 2;
					}
					else
						Num = Num*10 +1;				
			}
				
		}
		
		number[k] = cnt; 
		value[k]  = Num;
		MAX = Math.max(MAX, cnt);
			
		
	}
	
	public static void main(String[] args) 
	{
	
		int T = 0; 
		T = in.nextInt();
		while(T-->0)
		{
			MAX = -1;
			String[] Name 	= new String[102];
			String Class	= "";
			String	end		= "class";
			
			int N=1; 
			N = in.nextInt();	
			
			for(int i =1 ;i <= N ;i ++)
			{
				
				Name[i] 	= in.next();						
				Class		= in.next();								
				end			= in.next();
				
				Name[i]  = Name[i].split(":")[0];
				Key[i] = i;
				value[i] 	= 0;
				number[i]	= 0;
				caculateClass(Class,i);
				
			}
			
			
			
			for(int i =1 ;i <= N ;i ++)
			{
				if(number[i] < MAX)
				{
					for(int j = number[i] ; j < MAX ;j ++)
					{
						value[i]= value[i]*10 + 3;
					}
				}
			}
			
			
			QuickSort(value,1,N);
			
			for(int i =1 ;i <= N ;i ++)
				System.out.print(value[i]+ " ");
			System.out.println();;
			for(int i =1 ;i <= N ;i ++)
			{
				
				System.out.println(Name[Key[i]]);
			}
			System.out.println("==============================");
			
			
			
		}
		

	}

}
