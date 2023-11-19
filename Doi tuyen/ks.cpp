#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long c[26];
long long n,k;
string s;
long long res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("amnhac.inp","r",stdin);
   // freopen("amnhac.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=n;i++) c[s[i]-'a']++;
    for (int i=0;i<26;i++) {
        c[i]*=k;
        res=max(res,c[i]);
    }
    for (int i=1;i<n;i++) {
        if (s[i]==s[i+1]) continue;
        int x=s[i]-'a';
        int y=s[i+1]-'a';
        res=max(res,c[x]+c[y]);
    }
    for (int i=2;i<=n;i++) {
        if (s[i]==s[i-1]) continue;
        int x=s[i]-'a';
        int y=s[i-1]-'a';
        res=max(res,c[x]+c[y]);
    }
    cout<<res;
}
