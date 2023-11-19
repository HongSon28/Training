#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
int inc[N+5],decr[N+5];
int main() {
    freopen("LADDER.INP","r",stdin);
    freopen("LADDER.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    inc[n]=1;
    decr[n]=1;
    for (int i=n-1;i>=1;i--) {
        if (a[i]<=a[i+1]) inc[i]=inc[i+1]+1;
        else inc[i]=1;
        if (a[i]>=a[i+1]) decr[i]=decr[i+1]+1;
        else decr[i]=1;
    }
    while (m--) {
        int l,r;
        cin>>l>>r;
        int t=l+inc[l]-1;
        if (t>=r) {
            cout<<"Yes"<<endl;
            continue;
        }
        t=t+decr[t]-1;
        if (t>=r) {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}
