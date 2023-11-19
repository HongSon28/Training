#include<bits/stdc++.h>
using namespace std;
string s,t;
const int N=1e6;
long long MOD=1e9+7;
long long power[N+5],hashs[N+5],hasht[N+5];
long long base=311;
void create_hash_s()
{
    power[0] = 1;
    for (int i = 1; i < s.size(); i++)
        power[i] = (power[i - 1] * base) % MOD;

    for (int i = 1; i < s.size(); i++)
        hashs[i] = (hashs[i - 1] * base + (int)s[i]) % MOD;
}
void create_hash_t() {
    for (int i = 1; i < t.size(); i++)
        hasht[i] = (hasht[i - 1] * base + (int)t[i]) % MOD;
}
long long get_hash_s(int l, int r)
{
    return (hashs[r] - hashs[l - 1] * power[r - l + 1] + MOD * MOD) % MOD;
}
long long get_hash_t(int l, int r)
{
    return (hasht[r] - hasht[l - 1] * power[r - l + 1] + MOD * MOD) % MOD;
}
int len;
int start;
int main() {
    freopen("MPALIND.INP","r",stdin);
    freopen("MPALIND.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    int n=s.length();
    t=s;
    reverse(t.begin(),t.end());
    t=' '+t;
    s=' '+s;
    create_hash_s();
    create_hash_t();
    for (int i=1;i<=n;i++) {
        int res=0,lo=1,hi=min(i-1,n-i);
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            int left=i-mid,right=i+mid;
            if (get_hash_s(left,i)==get_hash_t(n-right+1,n-i+1)) {
                res=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        if (res*2+1>len) {
            len=res*2+1;
            start=i-res;
        }
    }
    for (int i=1;i<n;i++) {
        int j=i+1;
        if(s[i]!=s[j]) continue;
        int res=0,lo=1,hi=min(i-1,n-j);
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            int left=i-mid,right=j+mid;
            if (get_hash_s(left,i)==get_hash_t(n-right+1,n-j+1)) {
                res=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        if (res*2+2>len) {
            len=res*2+2;
            start=i-res;
        }
    }
    cout<<s.substr(start,len);
}
