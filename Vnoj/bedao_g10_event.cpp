#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
long long p[N+5];
long long sum[N+5];
int c,k;
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>p[i];
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
    while (q--) {
        cin>>c>>k;
        int t1=c/(k+1);
        int t2=c-t1;
        //cout<<t1<<' '<<t2<<endl;
        cout<<sum[n-t1]-sum[n-t1-t2]+(sum[n]-sum[n-t1])*2<<endl;
    }
}
