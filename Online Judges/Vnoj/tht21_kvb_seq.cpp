#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n+1],sum[n+1];
    long long res=-1e18;
    sum[0]=0;
    map<long long,vector<long long>>mp;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        mp[a[i]].push_back(i);
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        vector<long long>t=i->second;
        for (int m=0;m<t.size()-1;m++) {
            for (int n=m+1;n<t.size();n++) {
                res=max(res,sum[t[n]]-sum[t[m]-1]);
            }
        }
    }
    cout<<res;
}
