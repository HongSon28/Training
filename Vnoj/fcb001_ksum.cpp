#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long w[N+5];
long long sum;
long long res;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=k;i++) sum+=w[i];
    res=sum;
    for (int i=k+1;i<=n;i++) {
        sum+=w[i];
        sum-=w[i-k];
        res=max(res,sum);
    }
    cout<<res;
}
