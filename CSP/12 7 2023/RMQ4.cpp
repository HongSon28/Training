#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int MX=20;
int n;
int a[N+5];
int rm1[N+5][MX+1],rm2[N+5][MX+1];
long long res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("RMQ4.INP","r",stdin);
    freopen("RMQ4.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rm1[i][0]=a[i];
        //rm2[i][0]=a[i];
    }
    for (int j=1;j<=MX;j++) {
        for (int i=1;i<=n-(1<<j)+1;i++) {
            rm1[i][j]=min(rm1[i][j-1],rm1[i+(1<<(j-1))][j-1]);
            //rm2[i][j]=max(rm2[i][j-1],rm2[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i=1;i*i<=n;i++) {
        if (n%i!=0) continue;
        long long cur=0;
        for (int j=1;j<=n/i;j++) {
            int l=(j-1)*i+1,r=j*i;
            int k=__lg(i);
            long long mn=min(rm1[l][k],rm1[r-(1<<k)+1][k]);
            cur+=mn*i*i;
        }
        //cout<<i<<' '<<cur<<endl;
        res=max(res,cur);

        cur=0;
        for (int j=1;j<=i;j++) {
            int l=(j-1)*n/i+1,r=j*n/i;
            int k=__lg(n/i);
            long long mn=min(rm1[l][k],rm1[r-(1<<(k))+1][k]);
            cur+=mn*(n/i)*(n/i);
        }
        //cout<<n/i<<' '<<cur<<endl;
        res=max(res,cur);
    }
    cout<<res;
}

