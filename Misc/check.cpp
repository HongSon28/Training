#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100001],sum[100001];
int res=0,resx;
void tknp (int m) {
    int lo=1,hi=m;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (a[m]*(m-mid+1)-(sum[m]-sum[mid-1])<=k) {
            cout<<lo<<' '<<hi<<' '<<mid<<' '<<"T"<<endl;
            if (res<m-mid+1) {
                res=m-mid+1;
                resx=a[m];
            }
            hi=mid;
        } else {
            cout<<lo<<' '<<hi<<' '<<mid<<' '<<"F"<<endl;
            lo=mid+1;
        }
    }
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) sum[i]+=sum[i-1]+a[i];
    sort(a+1,a+1+n);
    tknp(4);
    cout<<res<<' '<<resx;
}

