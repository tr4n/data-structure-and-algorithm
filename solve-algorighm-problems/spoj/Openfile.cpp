#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;

 
int n = 0;

typedef struct No 
{
	string Code; 
	string Course; 
 	string WeekDay; 
	string Hours; 
 	string Period; 
 	string Week; 
	string Room; 
	string weekday(string S)
	{
		
		int a = (int)(S[2] - '0');
		if(a == 2) No.WeekDay =  "Monday";
		if(a == 3) No.WeekDay = "Tuesday";
		if(a == 4) No.WeekDay = "Wednesday";
		if(a == 5) No.WeekDay = "Thursday";
		if(a == 6) No.WeekDay = "Friday";
		
		return No.WeekDay;
	}
	
	
	string room(string S)
	{
		int len = S.length();
		string s;
		for(int i = len -7 ;i <= len -1 ;i ++)
			s.push_back(S[i]);
		
		No.Room = s;
		return s; 	
	
	}
	
	string hours(string S)
	{
		char x = S[3];
	
		if(x == '1') No.Hours =   "Morning";
		else No.Hours =  "Afternoon";
		
		return No.Hours; 
	
	}

	
	
	
};

vector <No> List;







string period(string S)
{
	string s; 
	s.push_back(S[4]);
	s.push_back('-');
	s.push_back(S[8]);
	return s;
}

string week(string S)
{
	string s ;
	int a = 10, len = S.length(),b; 
	for(b = len -1; b >= 0 ;b --)
	{
		if(S[b] == ',') break;
	}
	
	for(int i = a ;i < b ;i ++)
	s.push_back(S[i]);
	
	return s;
		
}


void Print()

{
		cout << Code    << " | "  << Course  << " | " 
		     << WeekDay << " | "  << Room    << " | "  
			 << Hours   << " | "  << Period  << " | "
			 << Week    << " | "
			 << endl;
}

void OpenFile()
{
	
	bool split_finish = false;
	string  s1,s2,s3;
	string In;
	
	while((cin >> In) )
	{
	 	int len = In.length()-1;
		
		if( In[len] >= '0' && In[len] <= '9')
		{
			s1 = In;
			
		}
		else 
		if( In[len] == ';')
			{
				s3 = In;
				split_finish = true;	
			}
		else
			s2 += (" "+In);
		
		if( split_finish)
		{
			n ++;
		
			Code 	= s1;
			Course	= s2;
			WeekDay	= weekday(s3);
			Room	= room(s3);
			Hours	= hours(s3);
			Period	= period(s3);
			Week	= week(s3);
			
			
			split_finish = false;
			s1 = "";
			s2 = "";
			s3 = "";
			
			Print();
		}
				
		
		
	}
	

	
}




main()

{
	freopen("Openfile.txt","r",stdin);
	OpenFile();
	
//	for(int i = 0;i < n ; i ++)
//	Print(i);
	
	
}
