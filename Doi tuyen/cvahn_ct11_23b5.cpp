#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,res;
long long a[N+5];
long long pre[N+5];
vector<pair<long long,long long>>v;
long long calc(long long l,long long r) {
    return floor(sqrt(r-l+1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SX.INP","r",stdin);
    freopen("SX.OUT","w",stdout);
    cin>>n;
    for (long long i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]!=i)
            v.push_back({min(i,a[i]),max(i,a[i])});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++) pre[i]=i-1;
    for (int i=0;i<v.size()-1;i++) {
        long long t1=calc(v[i].first,max(v[i].second,v[i+1].second));
        long long t2=calc(v[i].first,v[i].second)+calc(v[i+1].first,v[i+1].second);
        if (t1<=t2) {
            v[i+1].first=v[i].first;
            v[i+1].second=max(v[i].second,v[i+1].second);
            pre[i+1]=pre[i];
        }
    }
    while (true) {
        int temp=pre[v.size()-1];
        int last=v.size()-1;
        int cnt=0;
        while (temp!=-1) {
            long long t1=calc(v[temp].first,max(v[temp].second,v[last].second));
            long long t2=calc(v[temp].first,v[temp].second)+calc(v[last].first,v[last].second);
            if (t1<=t2) {
                v[last].first=v[temp].first;
                v[last].second=max(v[temp].second,v[last].second);
                pre[last]=pre[temp];
                cnt++;
            }
            last=temp;
            temp=pre[temp];
        }
        if (cnt==0) break;
    }
    res+=calc(v[v.size()-1].first,v[v.size()-1].second);
    int temp=pre[v.size()-1];
    while (temp!=-1) {
        res+=calc(v[temp].first,v[temp].second);
        temp=pre[temp];
    }
    cout<<res;
}
