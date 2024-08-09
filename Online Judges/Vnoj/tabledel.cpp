#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,k;
long long nn;
int row[N+5];
int col[N+5];
long long res;
int main() {
    cin>>n>>m>>k;
    res=n*m;
    nn=n;
    while (k--) {
        int x,y;
        cin>>x>>y;
        row[x]++;
        col[y]++;
    }
    for (int i=1;i<=n;i++)
        if (row[i]==0) {
            nn--;
            res-=m;
        }
    for (int i=1;i<=m;i++)
        if (col[i]==0)
            res-=nn;
    cout<<res;
}
