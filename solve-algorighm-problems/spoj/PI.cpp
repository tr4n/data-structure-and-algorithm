#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

#define For(i,a,b) for(int i = a ;i <= b ;i ++)
#define FOR(i,a,b) for(int i = a ;i >= b ; i --)
#define MAX 2

using namespace std; 

const int MAXSANG = 1000000;
 
int snt[MAXSANG+1];
 
sangnt()
{
    long i,j;
    for (i=1; i<=MAXSANG; i++)
        snt[i]=1;
    snt[1]=0;
    i=2;
    while (i<=sqrt(MAXSANG))
    {
        while (snt[i]==0)
            i++;
        for (j=2; j<=MAXSANG/i; j++)
            snt[i*j]=0;
        i++;
    }
}
 
main()
{
	int N,cnt=0; 
	cin >> N; 
    sangnt();
 for (int i=1; i<=N; i++)
 if (snt[i]) cnt++; 
 
    cout << cnt << endl;
}


