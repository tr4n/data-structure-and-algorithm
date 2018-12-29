#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

bool isChar(char x)
{
	return x == 'C' || x == 'H' || x == 'O'|| x == 'N';
	
}

int Vchar(char x)
{
	if(x == 'C') return 12; 
	if(x == 'H') return 1;
	if(x == 'O') return 16;
	if(x == 'N') return 14;
}

int Vnum(char x)
{
	return x - '0';
}

bool isNum(char x)
{
	return x >= '0' && x <= '9';
}


main()
{
	/*
	//system("color FC");
	cout	<< "---------------------------------------------------------------- " << endl;
	cout	<< "		                            *                           " << endl; 
	cout	<< "		                          * *                           " << endl;
	cout	<< "		    *      *  * *       *   *      * *  * * *           " << endl;
	cout	<< "		    *      * *   *    *     *        **      *          " << endl;
	cout	<< "		  * * *    **       * * * * * * *    *       *          " << endl;
	cout	<< "		    *      *                *        *       *          " << endl;
	cout	<< "		    *   *  *                *        *       *          " << endl;
	cout	<< "		     * *   *                *        *       *          " << endl;

	cout	<< "----------------------------------------------------------------" << endl;

//	system("color F0");
	
	

	cout << "  Enter the  a formula of a molecule : " ;

	*/
	string S; 
	cin >> S; 
	int value = 0,i = 0;
	stack <int> St;
	St.push(0);
	
	while(i < S.length())
	{
		char ch = S[i];
		if( isChar(ch) )
		{
			St.push(Vchar(ch));
			i++;
		}
		else
		if( isNum(ch))
		{
			value =  Vnum(ch);
			i++;
			while( isNum(S[i]))
			{
				value = 10*value + Vnum(S[i]);
				i++;
			}
			int num = St.top();
			St.pop();
			St.push(value* num);
		}
		else 
		if( ch == '(')
		{
			St.push(-1);
			i++;
		}
		else 
		if( ch == ')')
		{
			i++;
			value = 0;
			while( St.top() != -1)
			{
				
				value += St.top();
				St.pop();
			}
			St.pop();
			St.push(value);
			
		}
		
		
			
		
	}
	value = 0;
	while(!St.empty())
	{
		value += St.top();
		St.pop();
	}
	
	cout <<  value << endl;
	
	
}
