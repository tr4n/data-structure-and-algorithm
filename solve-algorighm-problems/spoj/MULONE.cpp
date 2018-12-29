#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>

#define For(i,a,b) for(int i = a ;i <= b ;i ++)
using namespace std; 

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

#define MAX 1000003
#define For(i,a,b) for(int i =a ;i <= b ;i ++)
using namespace std;
 

int         N,T,K;
char        res[2*MAX];
 
int main()
{
    cin >> T; 
    while (T--) {
        cin >> N; 
        K = 0;
        For(i,1,2*N-1) {
            if (i <= N)
                K += i;
            else
                K += 2*N-i;
            res[2*N-i] = K % 10 + 48;
            K/= 10;
        }
        For(i,1,2*N-1) cout << res[i];
        cout << endl;
    }
    
}





