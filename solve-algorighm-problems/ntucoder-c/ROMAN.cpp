#include<iostream>
#include<cmath>
using namespace std; 

inline int Value(char ch)
{
	switch(ch)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	return 0;
}

main()
{
	string S; 
	cin >> S; 
	char ch = S[0];
	int Sum = 0;
	for(int i = 0 ;i < S.length()-1; i ++)
	{
		char c = S[i];
		ch = S[i+1];
		if(Value(c) >= Value(ch))
		{
			Sum += Value(c);
		}
		else
		{
			Sum -= Value(c);
		}
		
		
	}
	
	cout << Sum + Value(S[S.length()-1]) << endl;	
}
