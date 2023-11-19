#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5],sum[N+5];
int main() {
    freopen("PARTITION.INP","r",stdin);
    freopen("PARTITION.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        if (sum[n]%sum[i]!=0) continue;
        int l=i+1,r=i+1;
        bool flag=true;
        while (r<=n) {
            if (sum[r]-sum[l-1]==sum[i]) l=r+1;
            else if (sum[r]-sum[l-1]>sum[i]) {
                flag=false;
                break;
            }
            r++;
        }
        if (flag) {
            cout<<sum[i];
            return 0;
        }
    }
}
