#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N+5];
long long sum[N+5];
long long mn[N+5];
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]-a[i];
    }
    for (int i=1;i<=n;i++) mn[i]=min(mn[i-1],sum[i]);
    for (int i=1;i<=n;i++) {
        long long temp= sum[i]-mn[i-1];
        res=max(res,temp);
    }
    cout<<res*2-sum[n];
}
