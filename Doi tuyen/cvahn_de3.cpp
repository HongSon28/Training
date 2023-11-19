#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+5],t[N+5],d[N+5];
int res,n;
string s;
int main() {
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<=n;i++) {
        a[i]=s[i]-'0';
        t[i]=t[i-1]+a[i];
    }
    int k=t[n]%3;
    for (int i=0;i<=n;i++) {
        int j=t[i]%3-k;
        if (j<0) j+=3;
        res+=d[j];
        d[t[i]%3]++;
    }
    if (k>0) res--;
    cout<<res;
}
