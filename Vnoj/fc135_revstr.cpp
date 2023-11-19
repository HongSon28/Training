#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
string s;
int n,m;
int c[N+5];
int a[N+5];
int main() {
    cin>>s;
    n=s.size();
    s=' '+s;
    cin>>m;
    for(int i=1;i<=m;i++) {
        int t;
        cin>>t;
        c[t]++;
    }
    for (int i=1;i<=n/2;i++) {
        a[i]=a[i-1]+c[i];
        a[n-i+1]=a[i];
    }
    for (int i=1;i<=n;i++)
        if (a[i]%2==0)  cout<<s[i];
        else cout<<s[n-i+1];
}
