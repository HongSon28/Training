#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long n,k,res;
long long b[N+5],h[N+5];
vector<long long>x,y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) {
        if (b[i]==0) x.push_back(h[i]);
        else y.push_back(h[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int i=0,j=0;
    while (i<x.size()&&j<y.size()) {
        if (x[i]-y[j]<=k&&x[i]>=y[j]) {
            i++;
            j++;
            res++;
        } else if (x[i]<y[j]) i++;
        else j++;
    }
    cout<<res;
}
