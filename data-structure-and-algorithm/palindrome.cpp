#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string MotherString;
string FatherString = " ";

int palindromicSubstring[100][100];
int length;

main()
{
    //getline(cin,MotherString);
    cin >> MotherString;
    length = MotherString.length();
    MotherString = " " + MotherString;

    for(int i = length ; i >= 1 ; i --)
        FatherString.push_back(MotherString[i]);

    for(int i = 0 ; i <= length ; i ++)
    {
        palindromicSubstring[i][0] = palindromicSubstring[0][i] = 0;
    }

    for(int i = 1 ; i <= length; i++)
    {
        for(int j = 1; j <= length ; j ++)
        {
            if(MotherString[i] == FatherString[j])
            {
                palindromicSubstring[i][j] = palindromicSubstring[i-1][j-1] + 1;
            }
            else
                palindromicSubstring[i][j] = max(palindromicSubstring[i-1][j], palindromicSubstring[i][j-1]);

        }
    }

    int i = length, j = length;
    while(i*j)
    {
        if(MotherString[i] == FatherString[j])
        {
            cout << MotherString[i];
            i --;
            j--;
            continue;
        }
        if(palindromicSubstring[i][j] == palindromicSubstring[i-1][j]) i--;
        else			j--;

    }

}
