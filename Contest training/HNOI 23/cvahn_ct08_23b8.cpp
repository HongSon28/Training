#include<bits/stdc++.h>
using namespace std;
string x,y;
set<string>st1,st2;
string res="0";
string getmax(string x, string y) {
    while (x[0]=='0') x.erase(0,1);
    while (y[0]=='0') y.erase(0,1);
    if (x.size()>y.size()) return x;
    if (x.size()<y.size()) return y;
    for (int i=0;i<x.size();i++) {
        if (x[i]>y[i]) return x;
        if (x[i]<y[i]) return y;
    }
    if (x.size()==0) return "0";
    return x;
}
int main() {
    freopen("XAUCHUNGMAX.INP","r",stdin);
    freopen("XAUCHUNGMAX.OUT","w",stdout);
    cin>>x>>y;
    int n=x.size(),m=y.size();
    x=' '+x,y=' '+y;
    for (int i=1;i<=n;i++) {
        string s;
        for (int j=i;j<=n;j++) {
            if (x[j]<'0'||x[j]>'9') break;
            s+=x[j];
            st1.insert(s);
        }
    }
    for (int i=1;i<=m;i++) {
        string s;
        for (int j=i;j<=m;j++) {
            if (y[j]<'0'||y[j]>'9') break;
            s+=y[j];
            st2.insert(s);
        }
    }
    for (auto t:st1) {
        if (st2.count(t)==0) continue;
        res=getmax(res,t);
    }
    cout<<res;
}
