#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#define MAX 10000
#define oo	199999998

using namespace std;


class STACK
{

		stack <int> St;
		int Max[MAX];
		int Min[MAX];
		int Mid[MAX];
		int n;

	public:	
		
		void Init()
		{
			Max[0] = -oo;
			Min[0] = oo;
			Mid[0] = -oo;
			n = 0;			
		}
		
		void Push(int x)
		{
			St.push(x);
			n ++;
			
			Max[n] = max(Max[n-1],x);
		
			Min[n] = min(Min[n-1],x);
			
			if(n > 2 && Max[n] != Max[n-1])
			{
				Mid[n] = Max[n-1];
			}
			else 
			if( Mid[n-1] == -oo && x > Min[n] && x < Max[n])
				Mid[n] = x;
			else Mid[n] = Mid[n-1];
		}
		
		inline Pop()
		{
			St.pop();
			n --;
						
		}
		
		inline Top()
		{
			return St.top();
		}
		
		inline getMax()
		{
			if(Max[n] != -oo)
			return Max[n];
			
			
		}
		
		inline getMid()
		{
			if(Mid[n] != -oo)
			return Mid[n];
			
			 
		}
		
		inline getMin()
		{
			if(Min[n] != oo)
			return Min[n];
			
			 
		}
		
		inline Size()
		{
			
			return n;
		}
	
};

main()
{
	freopen("inSTACK.txt","r",stdin);
	STACK ST;
	ST.Init();
	char ch;
	int x; 
	
	
	while(cin >> ch)
	{
		 if(ch < 'A' || ch > 'Z' )cout << ch << " . ";
		switch(ch)
		{
			case '+': cin>> x;
				cout << x << " : ";
				 ST.Push(x);
				 break;
			case'-': ST.Pop();
					cout << "    "; 
				 break;
			case'S': cout   << ST.Size() << " ";
				 break;
			case'A': cout << ST.getMax() << " ";
				 break;
			case'B': cout << ST.getMid() << " ";
				 break;
			case'C': cout << ST.getMin() << " ";
				 break;
			case 'E': cout << endl;
				 break;
			
		
		}
		
	}
	

	
	
}
