#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long a[N+5],sum,res;
int main() {
    freopen("EXPRESS.INP","r",stdin);
    freopen("EXPRESS.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (i+1==j) {
                long long temp=sum-a[i]-a[i+1]-a[i+2];
                temp+=a[i]*a[i+1]*a[i+2];
                res=max(res,temp);
            } else {
                long long temp=sum-a[i]-a[i+1]-a[j]-a[j+1];
                temp+=a[i]*a[i+1]+a[j]*a[j+1];
                res=max(res,temp);
            }
        }
    }
    cout<<res;
}
