#include<bits/stdc++.h>
using namespace std;
long long l,r;
long long res,N=1e6;
bool check(long long n) {
    long long temp=l/n;
    if (l%n!=0) temp++;
    if (temp*n<=r) return true;
    return false;
}
long long calc(long long l,long long r) {
    return (r+l)*(r-l+1)/2;
}
vector<pair<long long, long long>>vc;
int main() {
    freopen("SUMDIV.INP","r",stdin);
    freopen("SUMDIV.OUT","w",stdout);
    cin>>l>>r;
    for (long long i=1;i<N;i++) {
        if (check(i)) res+=i;
    }
    for (long long v=1;v<=1000;v++) {
        long long lo=(l+v-1)/v;
        long long hi=r/v;
        if (lo>hi||hi<N) continue;
        lo=max(lo,N);
        vc.push_back(make_pair(lo,hi));
    }
    if (vc.empty()) {
        cout<<res;
        return 0;
    }
    sort(vc.begin(),vc.end());
    for (int i=0;i<vc.size()-1;i++) {
        if (vc[i].second>=vc[i+1].first) {
            vc[i+1].first=min(vc[i].first,vc[i+1].first);
            vc[i+1].second=max(vc[i].second,vc[i+1].second);
        } else res+=calc(vc[i].first,vc[i].second);
    }
    res+=calc(vc.back().first,vc.back().second);
    cout<<res;
}
