#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int res;
void rec(int k,int sum) {
    if (k==n) {
        if (sum==m) res++;
        return;
    }
    for (int i=1;i<=3;i++) {
        if (i==1) rec(k+1,sum+(int)(s[k+1]-'0'));
        else if (i==2) rec(k+1,sum-(int)(s[k+1]-'0'));
        else rec(k+1,sum);
    }
}
int main() {
    freopen("DATPT.INP","r",stdin);
    freopen("DATPT.OUT","w",stdout);
    cin>>s>>m;
    n=s.size();
    s=' '+s;
    rec(0,0);
    cout<<res;
}
