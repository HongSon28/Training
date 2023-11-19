#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,k,cnt,res=INT_MAX;
int c[26];
string s;
int main() {
    freopen("DELSTR.INP","r",stdin);
    freopen("DELSTR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>k;
    cin>>s;
    n=s.size();
    s=' '+s;
    int l=1,r=1;
    c[s[1]-'A']++;
    if (c[s[1]-'A']==k) cnt++;
    while (l<=n&&r<=n) {
        while(cnt<m&&r<n) {
            r++;
            c[s[r]-'A']++;
            if (c[s[r]-'A']==k) cnt++;
        }
        if (cnt>=m) res=min(res,r-l+1-m*k);
        c[s[l]-'A']--;
        if (c[s[l]-'A']==k-1) cnt--;
        l++;
    }
    cout<<res;
}
