#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int Node(char ch)
{
	if(ch >= '0' && ch <= '9') return (int)(ch -'1')+1;
	
	if(ch == '.' || ch == ',' || ch == '?' || ch == '!')
		return 1;
	if(ch == '_') 
		return 0;
	if(ch >= 'a' && ch <= 'r')
		return ((int)((ch-'a')/3)+2);
	if(ch == 's')
		return 7;
	if(ch == 't'|| ch == 'u'|| ch == 'v')
		return 8;
	return 9;	
	
	
	
	
}

int Time(char ch)
{
	int node = Node(ch);
	if(ch >='0' && ch <= '9')
	{
		switch(ch )
		{
			case '0': return 2; 
			case '1': return 5;
			case '2': return 4; 
			case '3': return 4; 
			case '4': return 4;
			case '5': return 4; 
			case '6': return 4;
			case '7': return 5;
			case '8': return 4; 
			case '9': return 5;
			
		}
	}
	switch(node)
	{
		case 2: return (int)(ch -'a')+1;
		case 3: return (int)(ch -'d')+1;
		case 4: return (int)(ch -'g')+1;
		case 5: return (int)(ch -'j')+1;
		case 6: return (int)(ch -'m')+1;
		case 7: return (int)(ch -'p')+1;
		case 8: return (int)(ch -'t')+1;
		case 9: return (int)(ch -'w')+1;
		case 0: return 1;
		case 1:
		{
			if(ch == '.') return 1;
			if(ch == ',') return 2;
			if(ch == '?') return 3;
			if(ch == '!') return 4;
		}
	}
	
	
}

main()
{
	int N,node,time; 
	string S;
	cin >> N; 
	while(N--)
	{
		time = 0;
		node = 1;
		cin >> S; 
		for(int i = 0 ;i < S.length(); i++)
		{
			char ch = S[i];
			if(Node(ch) != node)
			{
				time += (1 + Time(ch));
			}
			else
			{
				time += Time(ch);
			}
			node = Node (ch);
		}
		cout << time << endl;
	}
	
	
}
