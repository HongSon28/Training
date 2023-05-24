#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,k,m,mx;
long long a[N+5],b[N+5],c[N+5];
long long sum[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]++;
        mx=max(mx,a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=mx;i>=0;i--) {
        b[i]=b[i+1]+c[i+1];
        sum[i]=sum[i+1]+b[i];
        //cout<<i<<' '<<sum[i]<<endl;
    }
    while (k--) {
        cin>>m;
        int lo=0,hi=mx;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (sum[mid]>=m) lo=mid;
            else hi=mid-1;
        }
        cout<<lo<<' ';
    }
}

