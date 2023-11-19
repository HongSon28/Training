#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e5;
long long MOD=1e9+7;
long long power[N+5],hashh[N+5];
long long base=311;
void create_hash()
{
    power[0] = 1;
    for (int i = 1; i < s.size(); i++)
        power[i] = (power[i - 1] * base) % MOD;

    for (int i = 1; i < s.size(); i++)
        hashh[i] = (hashh[i - 1] * base + (int)s[i]) % MOD;
}
long long get_hash(int l, int r)
{
    return (hashh[r] - hashh[l - 1] * power[r - l + 1] + MOD * MOD) % MOD;
}
int main() {
    freopen("ZFUNC.INP","r",stdin);
    freopen("ZFUNC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    int n=s.length();
    s=' '+s;
    create_hash();
    for (int i=1;i<=n;i++) {
        int res=0,lo=1,hi=n-i+1;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (get_hash(1,mid)==get_hash(i,i+mid-1)) {
                res=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        cout<<res<<' ';
    }
}
