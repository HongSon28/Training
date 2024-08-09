#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
long long k;
long long a[N+5],sum[N+5];
long long res=1e9;
long long st;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            long long temp=sum[i]-sum[j-1];
            if (temp==k) {
                if (res>i-j+1) {
                    res=i-j+1;
                    st=j;
                }
            }
        }
    }
    if (st!=0) cout<<st<<' '<<res;
    else cout<<0;
}
