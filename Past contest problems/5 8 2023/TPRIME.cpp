#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,k;
long long a[N+5];
long long cost[N+5];
long long sum[N+5];
long long res=1e18;
bool p[N+5];
vector<long long>prime;
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (long long j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("TPRIME.INP","r",stdin);
    freopen("TPRIME.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        int j=lower_bound(prime.begin(),prime.end(),a[i])-prime.begin();
        cost[i]=abs(prime[j]-a[i]);
        if (j!=0) {
            j--;
            cost[i]=min(cost[i],abs(a[i]-prime[j]));
        }
        sum[i]=sum[i-1]+cost[i];
    }
    for (int i=k;i<=n;i++) {
        int j=i-k+1;
        res=min(res,sum[i]-sum[j-1]);
    }
    cout<<res;
}
