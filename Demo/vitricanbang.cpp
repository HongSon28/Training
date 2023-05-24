#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        bool flag=false;
        cin>>n;
        long long a[n+1],sum[n+1];
        sum[0]=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for (int i=1;i<=n;i++) {
            long long suml=sum[i-1],sumr=sum[n]-sum[i];
            if (suml==sumr) {
                cout<<i<<' ';
                flag=true;
            }
        }
        if (flag==false) cout<<-1;
        cout<<endl;
    }
}
