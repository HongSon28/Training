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
vector<int>v;
int main() {
    freopen("MATCH.INP","r",stdin);
    freopen("MATCH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=' '+s;
    t=' '+t;
    create_hash_s();
    create_hash_t();
    for (int i=1;i<=m-n+1;i++) {
        if (get_hash_s(1,n)==get_hash_t(i,i+n-1)) v.push_back(i);
    }
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i<<' ';
}
