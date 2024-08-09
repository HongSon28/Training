#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
long long sum[N+5];
long long res=1e18;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        long long left=sum[i],right=sum[n]-sum[i];
        long long dif=abs(left-right);
        res=min(res,dif);
    }
    cout<<res;
}
