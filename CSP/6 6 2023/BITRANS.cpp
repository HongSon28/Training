#include<bits/stdc++.h>
using namespace std;
string pluss (string a, string b) {
    string res;
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)+(b[i]-48)+rem;
        rem=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if (rem!=0) {
        res=char(rem+48)+res;
    }
    return res;
}
int main() {
    freopen("BITRANS.INP","r",stdin);
    freopen("BITRANS.OUT","w",stdout);
    string dp0[1001]={},dp1[1001]={};
    dp0[0]="0",dp1[0]="0";
    for (int i=1;i<=1000;i++) {
        if (i%2==1) {
            dp0[i]=pluss(dp0[i-1],dp1[i-1]);
            dp1[i]=pluss(dp0[i-1],dp1[i-1]);
        } else {
            dp0[i]=pluss(dp0[i-1],dp1[i-1]);
            dp0[i]=pluss(dp0[i],"1");
            dp1[i]=pluss(dp0[i-1],dp1[i-1]);
        }
    }
    int n;
    while (cin>>n) cout<<dp0[n]<<endl;
}
