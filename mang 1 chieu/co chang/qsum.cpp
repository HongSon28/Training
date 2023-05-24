#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int sum[n+1];
    sum[0]=0;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=0;i<q;i++) {
        int a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<endl;
    }
}
