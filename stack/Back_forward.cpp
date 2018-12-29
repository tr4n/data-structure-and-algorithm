#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<stack>

using namespace std; 

stack<string> Back; 
stack<string> Forward; 

int n = 0;


bool Exit = false;
bool Ok = false;

bool OK(string S);
void BACK();
void FORWARD();
void CANCEL();
void FREE();

void FREE()
{
	
	while(Back.size())
		Back.pop();
	while(Forward.size())
		Forward.pop();
	cout << endl;
	cout << "		OK, Deleted all of the statements " << endl;
	cout << endl;
}


bool OK(string S)
{
	string s= "";
	for(int i = 0 ;i < S.length() ;i ++)
		s.push_back(toupper(S[i]));
	s.push_back('\n');
	return (S == "BACK" || S == "FORWARD" || S == "EXIT" || 
			S == "YES"   	              || S  == "FREE"||
			S == "Back" || S == "Forward" || S == "Exit" || 
			S == "Yes"   	              || S  == "Free"||
			S == "back" || S == "forward" || S == "exit" || 
			S == "yes"   	              || S  == "free");
}
void CANCEL()
{
	if(Back.size() == n) 
		return; 
	else
	if(Back.size() < n)
	{
		for(int i = 0 ;i < n - Back.size() ;i ++) 
		{
			Back.push(Forward.top());
			Forward.pop();
		}
		return;
	}			
	else
	{
		for(int i = 0 ;i < Back.size() -n ;i ++) 
		{
			Forward.push(Back.top());
			Back.pop();
		}
		return;
	}	
	
}


void BACK()
{
	string s="..";
	if(Back.empty())
	{
		cout << endl;
		cout <<"  There aren't any action statements to Back !!" << endl;
		cout << endl;
		return;
	}
	else
	{
		Forward.push(Back.top());
		Back.pop();
		cout << endl;
		cout << "   Do you want to execute [" << Forward.top() << "] ? " << endl;
		cout << "   Write YES to cofirm" << endl ;
		cout << " 	 Back : BACK   ||  Forward : FORWARD || exit program: EXIT   "  << endl;
		cout << endl;
		
		while(!OK(s)) cin >> s;
			
		if("YES" == s || "yes" == s || "Yes" == s) 
		{
			cout << endl;												
			cout<< "   OK, do [ " << Forward.top() << " ]" << endl;	
			cout << endl;
			return;
		}
		
		else	
		if("FORWARD" == s || "forward" == s || "Forward" == s)
		{
			Back.push(Forward.top());
			Forward.pop();
			FORWARD();
			return;		
		}
		
		else
		if("BACK" == s || "Back" == s || "back" == s)
		{
			BACK();
			return;
		}
		
		else if("EXIT" == s || "exit" == s || "Exit" == s)
		{
			Exit = true;
			return;
		}
	
		

}
		
		
	
	
}

void FORWARD ()
{
	string s="..";
	if(Forward.empty())
	{
		cout << endl;
		cout <<"  There aren't any action statements to Forward !!" << endl;

		cout << endl;
		return; 
	}
	else
	{
		Back.push(Forward.top());
		Forward.pop();
		cout << endl;
		cout << "   Do you want to execute [" << Back.top() << "] ? " << endl;
		cout << "   Write YES to cofirm" << endl ;
		cout << " 	 Back : BACK   ||  Forward : FORWARD || exit program: EXIT  " << endl;
		cout << endl;
		
		while(!OK(s)) cin >> s;
			
		if("YES" == s || "yes" == s || "Yes" == s)
		{	
			cout << endl;											
			cout<< "   OK, do [ " << Back.top() << " ]" << endl;
			cout << endl;	
			return;
		}
		
		else	
		if("FORWARD" == s || "forward" == s || "Forward" == s)
		{
			FORWARD();
			return;		
		}
		
		else
		if("BACK" == s || "Back" == s || "back" == s)
		{
			Forward.push(Back.top());
			Back.pop();
			BACK();
			return;
		}
		
		else if("EXIT" == s || "exit" == s || "Exit" == s)
		{
			Exit = true;
			return;
		}
	
		
	}
}
main()
{

	string S="..................";
	string line;
	cout << " Write your action statements" << endl;
	cout <<"  Press ENTER in your keybroad to finish each statement " << endl;
	cout << " Note: " << endl;
	cout << " 	 Back : BACK   ||  Forward : FORWARD || exit program: EXIT  || free memory : FREE " << endl;  
	
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
							 
	while(!Exit)	
	{
		
		
		cin >> S; 
		
	
	 if("EXIT" == S || "exit" == S || "Exit" == S)
		{
			break;
		}
		else
		if("BACK" == S || "Back" == S || "back" == S)
		{
			
			BACK();
		}
		
		else 
		if("FORWARD" == S || "forward" == S || "Forward" == S)
		{
		
			FORWARD();
		}
		else if("FREE" == S || "free" == S || "Free" == S)
		{
			FREE();	
		}
		else 
		{
			Back.push(S);
		}		
				
				
				
	}
	
	
	
}
