#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
#define f1(i,n) for (int i=1; i<=n; i++)
int n, m, cnt;
vector<int> a[N];
int Visited[N], Parent[N];

void visit(int u){
    cout << "Visiting " << u << endl;
    Visited[u]=++cnt; // travesal time
    for (int i=0,v; v=a[u][i]; i++)
    if (v!=Parent[u]){
        if (!Visited[v]){
            Parent[v]=u;
            visit(v);
        }
    }
}

main(){
    cin >> n >> m;
    f1(i,m) {
        int p, q;
        cin >> p >> q;
        /*do {
            p=rand()%n+1;
            q=rand()%n+1;
        } while (p==q);
        cout << p << " " << q << endl;*/
        a[p].push_back(q);
        a[q].push_back(p);
    }
    f1(i,n) a[i].push_back(0);
    f1(i,n) if (!Visited[i]) visit(i);
    cout << "Travesal time: " << endl;
    f1(i,n) cout << Visited[i] << " ";
    cout << endl;
    cin.ignore(2);
}
