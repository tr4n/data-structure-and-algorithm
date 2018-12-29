#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<bits/stdc++.h>
#include<cstring>
#include<string>
#include<stdlib.h>

using namespace std;




bool IsOperand(char x)
{
	return ( ( x >= 'a' && x <= 'z' )
		   ||( x >= 'A' && x <= 'Z' )
		   ||( x >= '0' && x <= '9' ));
}

bool TakesPrecedence(char OperatorA, char OperatorB)
{
	#define A OperatorA 
	#define B OperatorB 
	if(A == '(' || B == '(') 
		return false;
	else if( B == '(')
		return true;
	else if( A == '^' && B == '^')
		return false;
	else if( A == '^')
		return true;
	else if( B == '^')
		return false;
	else if( A == '*' || A == '/')
		return true;
	else if( B == '*' || B ==  '/')
		return false;
	else 
		return true;
	
}


void Infix_Postfix(string &Infix, string &Postfix )
{
	string in; 
	stack <char> Stack;
	while(cin >> in) Infix = Infix + in; 
	
	cout  << " Infix  P = "<<  Infix << endl;
	
	bool IsNumber = false;
	
	for(int i = 0 ;i < Infix.length(); i++)
	{
		char Symbol = Infix[i];
		
		if(IsOperand( Symbol))
		{
			if(!IsNumber)
			{
				IsNumber = true;
				Postfix = Postfix +  " " + Symbol;
				
			}
			else
			{
				Postfix = Postfix + Symbol;	
			}	
		
		
		}
		else 
		{
			IsNumber = false;
			while( !Stack.empty() &&TakesPrecedence(Stack.top(),Symbol))
			{
				char TopSymbol = Stack.top();
				Stack.pop();
				Postfix = Postfix + TopSymbol ; 
			}
			
			if(!Stack.empty() && Symbol == ')')
				Stack.pop();
			else
				Stack.push(Symbol);
		}
				
	}
	
	while(!Stack.empty())
	{
		Postfix = Postfix + Stack.top();
		Stack.pop();
	}
	
	
}


double Caculate(string Postfix)
{
	stack <double> St;
	int k = 0; 
	for(int i = 0 ;i < Postfix.length() ;)
	{
		char Symbol = Postfix[i];
		if(Symbol == ' ')
		{
			k = i+1;
			double Result = 0; 
			while(IsOperand(Postfix[k]))
			{
				Result = Result*10 + (double)(Postfix[k]-'0');
				k++;
			}
			St.push(Result);
			i = k;
		}
		else if(!IsOperand(Symbol))
		{
			double b = St.top();
			St.pop();
			double a = St.top();
			St.pop();
			double number =0;
			switch(Symbol)
			{
				case '+': number = a+b; break;
				case '-': number = a-b; break;
				case '*': number = a*b; break;
				case '/': number = a/b; break;
				case '^': number = pow(a,b); break;
				//case '%': number = a%b; break;
			}
			St.push(number);
			i++;
		}
	}
	
	return St.top();
	
}


main()
{
//	freopen("in_infix.txt","r",stdin);
	cout << "*************************************************" << endl;
	cout << "*    Enter the expression (e.g: 12+3*(3-4)  )   *" << endl;
	cout << "*                                               *" << endl;
	cout << "*   I wil give you the result of expression~    *" << endl;
	cout << "*                                               *" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
	cout << " Now, Your expression is:                      " << endl;
	 
	string Infix="",Postfix="";
	Infix_Postfix(Infix,Postfix);
	

	//	cout <<" Postix P =" <<  Postfix << endl;
	cout <<"          = " <<  Caculate(Postfix) << endl;
	
}
