#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
pair<long long,long long>p[N+5];
long long dp[N+5],res;
long long inf=1e18;
vector<long long>b(N+5,inf);
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    b[0]=-inf;
    for (int i=1;i<=n;i++) {
        long long k=upper_bound(b.begin(),b.end(),p[i].first-p[i].second)-b.begin();
        b[k]=min(b[k],p[i].first+p[i].second);
        res=max(res,k);
    }
    cout<<res;
}
