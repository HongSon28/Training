#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    int sum1[n+1],sum2[n+1],sum3[n+1];
    sum1[0]=0,sum2[0]=0,sum3[0]=0;
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        sum1[i]=sum1[i-1],sum2[i]=sum2[i-1],sum3[i]=sum3[i-1];
        if (t==1) sum1[i]++;
        else if (t==2) sum2[i]++;
        else sum3[i]++;
    }
    while (q--) {
        int l,r;
        cin>>l>>r;
        cout<<sum1[r]-sum1[l-1]<<' '<<sum2[r]-sum2[l-1]<<' '<<sum3[r]-sum3[l-1]<<endl;
    }
}
