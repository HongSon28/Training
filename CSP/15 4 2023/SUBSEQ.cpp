#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
int n,k,res=INT_MIN,sum=0;
int a[N+5];
int maxSum[N+5];
int main() {
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    maxSum[1]=max(a[1],0);
    for (int i=2;i<=n;i++)
        maxSum[i]=max({maxSum[i-1]+a[i],a[i],0});
    for (int i=1;i<k;i++)
        sum+=a[i];
    for (int i=k;i<=n;i++) {
        sum+=a[i]-a[i-k];
        res=max(res,sum+maxSum[i-k]);
    }
    cout<<res;
}
