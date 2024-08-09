#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long MOD=1e9+7;
string s,t;
long long power[N+5],hashs[N+5],hasht[N+5];
long long base=5;
int res,n,m;
void create_hash()
{
    int tmp;
    power[0]=1;
    for (int i=1;i<t.size();i++)
        power[i]=(power[i-1]*base)%MOD;

    for (int i=1;i<s.size();i++) {
        if (s[i]=='A') tmp=1;
        else if (s[i]=='C') tmp=2;
        else if (s[i]=='G') tmp=3;
        else tmp=4;
        hashs[i]=(hashs[i-1]*base+tmp)%MOD;
    }
    for (int i=1;i<t.size();i++) {
        if (t[i]=='A') tmp=1;
        else if (t[i]=='C') tmp=2;
        else if (t[i]=='G') tmp=3;
        else tmp=4;
        hasht[i]=(hasht[i-1]*base+tmp)%MOD;
    }
}
long long get_hashs(int l,int r)
{
    return (hashs[r]-hashs[l-1]*power[r-l+1]+MOD*MOD)%MOD;
}
long long get_hasht(int l,int r) {
    return (hasht[r]-hasht[l-1]*power[r-l+1]+MOD*MOD)%MOD;
}
bool check(int len) {
    set<long long>hs;
    int l=1,r=l+len-1;
    while (r<=n) {
        hs.insert(get_hashs(l,r));
        l++;
        r++;
    }
    l=1,r=l+len-1;
    while (r<=m) {
        if (hs.count(get_hasht(l,r))>0) return true;
        l++;
        r++;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>t;
    t+=t;
    n=s.size(),m=t.size();
    s=' '+s;
    t=' '+t;
    create_hash();
    int lo=0,hi=m;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
