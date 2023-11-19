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
    //freopen("PREF.INP","r",stdin);
    //freopen("PREF.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    int n=s.length();
    s=' '+s;
    create_hash();
    for (int i=1;i<=n;i++) {

    }
}

