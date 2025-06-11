#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int n;
int x[N+5],s[N+5];
map<int,long long>mp;
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>n;
    mp[0]++;
    for (int i=1;i<=n;i++) {
        cin>>x[i];
        s[i]=(s[i-1]^x[i]);
        mp[s[i]]++;
    }
    long long res=0;
    for (auto i=mp.begin();i!=mp.end();i++) {
    	long long t=i->second;
    	res+=t*(t-1)/2;
    }
    cout<<res;
}
