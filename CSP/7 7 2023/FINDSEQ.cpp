#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,s;
long long a[N+5];
int nex[N+5];
long long sum[N+5];
long long bs(int l) {
    int lo=1,hi=n-l+1;
    int res=0;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        int r=l+mid-1;
        if (sum[r]-sum[l-1]<=s) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    return l+res-1;
}
int main() {
    freopen("FINDSEQ.INP","r",stdin);
    freopen("FINDSEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        nex[i]=bs(i);
        //cout<<nex[i]<<' ';
    }
    for (int i=1;i<=n;i++) {
        int t=nex[i];
        bool flag=false;
        while (t>=i) {
            int len=t-i+1;
            int l=t+1,r=l+len-1;
            if (r>n) {
                t--;
                continue;
            }
            if (sum[r]-sum[l-1]<=s) {
                //cout<<i<<' '<<t<<' '<<l<<' '<<r<<' '<<sum[r]<<' '<<sum[l-1]<<' ';
                cout<<len*2<<endl;
                flag=true;
                break;
            }
            t--;
        }
        if (!flag) cout<<0<<endl;
    }
}
