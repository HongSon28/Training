#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long MOD=1e9+7;
string s;
int q;
int x,y,z,t;
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
    freopen("CHECK.INP","r",stdin);
    freopen("CHECK.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    s=' '+s;
    create_hash();
    cin>>q;
    while (q--) {
        cin>>x>>y>>z>>t;
        if (get_hash(x,y)==get_hash(z,t)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
