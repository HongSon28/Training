#include<bits/stdc++.h>
using namespace std;
int n,s;
int main() {
    freopen("MINNUM.INP","r",stdin);
    freopen("MINNUM.OUT","w",stdout);
    cin>>n>>s;
    int res[n+1];
    for (int i=n;i>1;i--) {
        if (s>9) {
            s-=9;
            res[i]=9;
        } else {
            res[i]=s-1;
            s=1;
        }
    }
    res[1]=s;
    for (int i=1;i<=n;i++)cout<<res[i];
}
