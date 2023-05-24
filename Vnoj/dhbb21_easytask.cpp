#include<bits/stdc++.h>
using namespace std;
long long res=INT_MIN;
long long n;
long long mn;
vector<long long> prime;
void sang() {
    bool isprime[n+1];
    for (int i=0;i<=n;i++) isprime[i]=true;
    for (int i=2;i<=n;i++) {
        if (isprime[i]==true) {
            prime.push_back(i);
            for (int j=i*2;j<=n;j+=i) {
                isprime[j]=false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    long long a[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    long long sum[n+1];
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    sang();
    for (int i=0;i<prime.size();i++) res=max(res,a[prime[i]]);
    mn=sum[1];
    for (int i=1;i<prime.size();i++) {
        res=max(res,sum[prime[i]]-mn);
        mn=min(mn,sum[prime[i]-1]);
    }
    cout<<res;
}
