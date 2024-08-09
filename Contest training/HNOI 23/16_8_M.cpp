#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long a[N+5],sum[N+5];
long long n,t;
void preprocess() {
    a[1]=1,a[2]=2,a[3]=2;
    sum[1]=1,sum[2]=3,sum[3]=5;
    for (int i=4;i<=N;i++) {
        a[i]=lower_bound(sum+1,sum+i,i)-sum;
        sum[i]=sum[i-1]+a[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    preprocess();
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<lower_bound(sum+1,sum+1+N,n)-sum<<'\n';
    }
}
