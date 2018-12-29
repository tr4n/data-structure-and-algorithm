#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;


bool isNum(char x)
{
	return '0' <= x && '9' >= x;
}

int valueNumber(char x)
{
	return (int)(x - '0');
}


main()
{
	freopen("inHAUTO.txt","r",stdin);
	string S; 
	stack <int> St; 
	int value = 0;
	
	getline(cin,S);
	S = " " + S;
	cout << S << endl;
	int i = 0; 
	while(i < S.length())
	{
		char ch = S[i];
		if(ch == ' ')
		{
			value = 0; 
			i++;	
		}	
			
		if( isNum(ch) )
		{
			value = 0;
			while( isNum(S[i]))
			{
				value = 10*value + valueNumber(S[i]);
				i++;
			}
			St.push(value);
			
		}
		else 
	
		switch(ch)
		{
			case '+' : 
			{
				i++;
				int a = St.top();
				St.pop();
				int b = St.top();
				St.pop();
				St.push(a+b);
				break;
			}
			
			case '-' : 
			{
				i++;
				int a = St.top();
				St.pop();
				int b = St.top();
				St.pop();
				St.push(b-a);
				break;
			}
				
			case '*' : 
			{
				i++;
				int a = St.top();
				St.pop();
				int b = St.top();
				St.pop();
				St.push(a*b);
				break;
			}
				
				
			
			
		}
		
	}
	
	
	value = 0;
	while(!St.empty())
	{
		value += St.top();
		St.pop();
	}
	
	cout << value << endl;
	
}
