#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,k;
string s;
long long a[N+5];
map<long long,long long>mp;
long long res,sum;
int main() {
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    for (long long i=1;i<=n;i++) {
        if (s[i]=='O') a[i]=1;
        else a[i]=-k;
    }
    for (long long i=1;i<=n;i++) {
        sum+=a[i];
        if (sum==0) {
            res=max(res,i);
        } else {
            if (mp[sum]==0) mp[sum]=i;
            else res=max(res,i-mp[sum]);
        }
    }
    cout<<res;
}
