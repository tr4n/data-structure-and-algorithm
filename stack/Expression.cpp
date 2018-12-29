/*
*	
*
*
*
*/


#include<iostream>
#include<cmath>
#include<cstring>
#include<string>

using namespace std; 

int Operand = 0, Operator = 0;
string S; 
int error = 0;
string errorPointer = "#";


inline bool IsOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

inline bool IsOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || 
			ch == '%' || ch == '%' || ch == '^' || ch == '='   );
			
}

bool Number()
{
	Operand = 0;
	Operator = 0;
	int equal = 0;
	int tmp = 0;
	if(S[0] == '+' || S[0] == '-')
		tmp =1;
	for(int i = tmp ;i < S.length() ;i ++)
	{
		char ch = S[i];
		if(ch == '=') equal ++;
		if(equal > 1) 
		{
			error = i;
			return false;
		}
		if( IsOperand(ch) ) 		 Operand ++;
		if( IsOperator(ch))		 Operator ++;
	}

	return Operand > Operator;
	return true;
	
}

bool Parenthes()
{
	error =0;
	int sum = 0; 
	for(int i = 0 ;i < S.length(); i++)
	{
		if(S[i] == ')' ) sum --;
		if(S[i] == '(' ) sum ++;
		if(0 > sum ) 
		{
			error = i ; 
			return false;	
		}	
			 
	}
	
	if( 0 != sum ) 
		return false;
		 
	return true;
}

bool Position()
{
	error = 0;
	int length = S.length();
	
	if(  (IsOperator(S[0]) && S[0] != '-' && S[0] != '+' )|| (S[0] == '!' ) )
		{
			error = 0 ; 
			return false;	
		}	
	if( !IsOperand(S[length-1]) && S[length-1] != ')' && S[length-1] != '!' )
		{
			error = length-1 ; 
			return false;	
		}	
	
	for(int i = 0 ;i < length-1 ;i ++)
	{
		if( IsOperand(S[i]) && IsOperand(S[i+1]) ) 
		{
			error = i ; 
			return false;	
		}	
		if( IsOperator(S[i]) && IsOperator(S[i+1]))
		{
			error = i ; 
			return false;	
		}	
		
		if('!' == S[i] && (!IsOperator(S[i+1])&& S[i+1] != ')'))
		{
			error = i ; 
			return false;	
		}	
		if(S[i+1] =='!' && !IsOperand(S[i]) && !S[i] != ')')
		{
			error = i; 
			return false;
		}
		if(IsOperand(S[i]) && ('(' == S[i+1] ) )	
		{
			error = i ; 
			return false;	
		}	
		if(S[i] == ')' && IsOperand(S[i+1]))
		{
			error = i; 
			return false;
		}
		if(S[i] == '(' && IsOperator(S[i+1]) )
		{
			if((S[i+1]!='-' && S[i+1] !='+'))
			{
				error = i; 
				return false;
			}
			
		}
		if(IsOperator(S[i]) &&  ')' == S[i+1] )
		{
			
			error = i ; 
			return false;	
		}	
		
	}
	
	return true;
}

bool Operatorcheck()
{
	
	
}

bool CHECK()
{
	return (Position() && Parenthes() && Number() ) ;
}
main()
{
	freopen("inExpression.txt","r",stdin);
	cout << " Enter expressions and check them true or false " << endl;
	cout << " e.g : A=1+2  --> true " << endl;
	cout << "       A=1+2+  ---> false " << endl;
	cout << endl;
	cout << " P/s: There isn't any SPACE in the expressions       " << endl;
	cout << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	while(cin >> S)
	{
		error = 0;
		
		cout <<"The Expression: "<<  S << endl;
		if(CHECK()) 
			cout << "	TRUE\n" << endl;
		else 
			cout << "	FALSE"<< endl;
			
		if(!CHECK())
		{
			if(!Position())
			{
				cout <<"	Position :" ;
				for(int i = 0 ;i < S.length() ;i ++)
				{
					cout << S[i] ;
					if(i == error) cout << errorPointer;
				}
				cout << endl;
			}
		
	
	
	
			if(!Parenthes())
			{
				cout << "	Parenthes: ";
				for(int i = 0 ;i < S.length() ;i ++)
				{
					cout << S[i] ;
					if(i == error) cout << errorPointer;
				}
				cout << endl;
			}
		
	
	
	
			if(!Number())
			{
				cout <<"	Number   : ";
				for(int i = 0 ;i < S.length() ;i ++)
				{
					cout << S[i] ;
					if(i == error) cout << errorPointer;
				}
				cout << endl;
			}
			cout << endl;
		}
	
		
	} 

	
	
	
	
	
	
	
		

}
