#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c[N];
int n,k;
int a,b;
int res;
map<int,int>mp;
int main() {
    freopen("LOTTERY.INP","r",stdin);
    freopen("LOTTERY.OUT","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    cin>>a>>b;
    for (auto i=mp.begin();i!=mp.end();i++) {
        int f=i->first,s=i->second;
        int t;
        t=a/f*f;
        if(t<a) t+=f;
        for (int j=t;j<=b;j+=f) {
            c[j-a]+=s;
        }
    }
    for (int i=a;i<=b;i++) {
        if (c[i-a]==k) res++;
    }
    cout<<res;
}
