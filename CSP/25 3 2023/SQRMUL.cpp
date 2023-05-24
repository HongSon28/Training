#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long t;
long long n;
long long a[N];
vector<long long>v;
void sang() {
    bool p[1001];
    memset(p,true,sizeof(p));
    for (int i=2;i<=1000;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=1000;j+=i) p[i]=false;
        }
    }
}
int main() {
    freopen("SQRMUL.INP","r",stdin);
    freopen("SQRMUL.OUT","w",stdout);
    sang();
    cin>>t;
    while (t--) {
        long long res=1;
        map<long long, long long>mp;
        cin>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) {
            a[i]=abs(a[i]);
            for (int j=0;j<v.size();j++) {
                int cnt=0;
                while (a[i]%v[j]==0) {
                    cnt++;
                    a[i]/=v[j];
                }
                if (mp[v[j]]<cnt) mp[v[j]]=cnt;
            }
        }
        for (auto i=mp.begin();i!=mp.end();i++) {
            long long f=i->first;
            long long s=i->second;
            if (s%2==1) s++;
            //cout<<f<<' '<<s<<endl;
            for (int j=1;j<=s;j++) {
                res*=f;
                res%=mod;
            }
        }
        cout<<res<<endl;
    }
}
