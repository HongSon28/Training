#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long MOD=1e9+7;
string s;
int n;
int f[N+5],g[N+5];
long long power[N+5],hashh[N+5];
long long base=311;
long long res;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   //freopen("CONCATST.INP","r",stdin);
    //freopen("CONCATST.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    create_hash();
    for (int i=1;i<=n;i++) {
        f[i]=-1;
        int lo=i,hi=n;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (get_hash(i,mid)==get_hash(1,mid-i+1)) {
                f[i]=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
    }
    for (int i=n;i>=1;i--) {
        g[i]=-1;
        int lo=1,hi=i;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (get_hash(mid,i)==get_hash(n-(i-mid+1)+1,n)) {
                g[i]=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
    }
    for (int i=1;i<=n;i++) {
        if (f[i]==-1) continue;
        for (int j=i+1;j<=n;j++) {
            if (g[j]==-1) continue;
            if (g[j]>=f[i]+1) res++;
        }
    }
    cout<<res;
}
