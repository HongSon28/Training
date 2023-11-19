#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n;
long long power[N+5],hashh[N+5];
long long base=311;
long long MOD=1e9+7;
void create_hash()
{
    power[0] = 1;
    for (int i = 1; i < s.size(); i++)
        power[i] = (power[i - 1] * base) % MOD;

    for (int i = 1; i < s.size(); i++)
        hashh[i] = (hashh[i - 1] * base + (int)s[i]) % MOD;
}
long long get_hash(long long l, long long r)
{
    return (hashh[r] - hashh[l - 1] * power[r - l + 1] + MOD * MOD) % MOD;
}
bool check(long long hs,long long len) {
    long long cur=len;
    long long l=1,r=len;
    while (cur+len<=n) {
        cur+=len;
        l+=len;
        r+=len;
        if (get_hash(l,r)!=hs) return false;
    }
    int temp=n-cur;
    if (get_hash(r+1,n)!=get_hash(1,temp)) return false;
    return true;
}
int main() {
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    create_hash();
    for (long long i=1;i<=n;i++) {
        if (check(get_hash(1,i),i)) cout<<i<<' ';
    }
}
