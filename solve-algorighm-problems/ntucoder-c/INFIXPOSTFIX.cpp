#include <iostream>
#include <string>
#include <stack>
//#include <ctype>   // to use the tolower function
 
using namespace std;
 
void Convert(const string & Infix, string & Postfix);
bool IsOperand(char ch);
bool TakesPrecedence(char OperatorA, char OperatorB);
void DisplayAnswer();

 
string postfix;

int main(void)
{
	 DisplayAnswer();
}
 
 
/* Given:  ch   A character.
   Task:   To determine whether ch represents an operand (here understood
           to be a single letter or digit).
   Return: In the function name: true, if ch is an operand, false otherwise.
*/
inline bool IsOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
 
/* Given:  OperatorA    A character representing an operator or parenthesis.
           OperatorB    A character representing an operator or parenthesis.
   Task:   To determine whether OperatorA takes precedence over OperatorB.
   Return: In the function name: true, if OperatorA takes precedence over
           OperatorB.
*/
bool TakesPrecedence(char OperatorA, char OperatorB)
{
    if (OperatorA == '(')
        return false;
    else if (OperatorB == '(')
        return false;
    else if (OperatorB == ')')
        return true;
    else if ((OperatorA == '^') && (OperatorB == '^'))
        return false;
    else if (OperatorA == '^')
        return true;
    else if (OperatorB == '^')
        return false;
    else if ((OperatorA == '*') || (OperatorA == '/'))
        return true;
    else if ((OperatorB == '*') || (OperatorB == '/'))
        return false;
    else
        return true;
}
 
 
/* Given:  Infix    A string representing an infix exp<b></b>ression (no spaces).
   Task:   To find the postfix equivalent of this exp<b></b>ression.
   Return: Postfix  A string holding this postfix equivalent.
*/
// (5 + 6) * 11 - 50 = 5 6 + 11 * 50 -
void Convert(const string & Infix, string & Postfix)
{
    stack<char> OperatorStack;
    char TopSymbol, Symbol;
    int k;
 
 	bool IsNumber = false;
    for (k = 0; k < Infix.size(); k++)
    {
    	
        Symbol = Infix[k];
        if (IsOperand(Symbol))
        {
        	if(!IsNumber) 
			{
				Postfix = Postfix + " " + Symbol;
				IsNumber = true;		
			}	
				
        	else
				Postfix = Postfix +  Symbol;  
        	
	}
            
        else
        {
        	IsNumber = false;
            while (!OperatorStack.empty() && TakesPrecedence(OperatorStack.top(), Symbol))
            {
                TopSymbol = OperatorStack.top();
                OperatorStack.pop();
                Postfix = Postfix +TopSymbol;
            }
            if (!OperatorStack.empty() && Symbol == ')')
                OperatorStack.pop();   // discard matching (
            else
                OperatorStack.push(Symbol);
        }
    }
    while (!OperatorStack.empty())
    {
        TopSymbol = OperatorStack.top();
        OperatorStack.pop();
        Postfix = Postfix +TopSymbol;
    }
}

void DisplayAnswer()
{

    string Infix,Postfix;   // local to this loop
 
    cout << "Enter an infix expression (e.g. (a+B)/c^2, with no spaces):" << endl;
    cin >> Infix;
 
    Convert(Infix, Postfix);
 
    cout << "The equivalent postfix expression is:" << endl;
    //cout << Postfix  << endl;
    for(int i = 1 ;i < Postfix.length(); i ++)
    	cout << Postfix[i];
       
	postfix = Postfix;	
 
}




