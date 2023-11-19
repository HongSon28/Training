#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int MX=20;
int n,s;
int a[N+5];
int rm1[N+5][MX+1],rm2[N+5][MX+1];
int start=1;
long long res=1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("RMQ2.INP","r",stdin);
    //freopen("RMQ2.OUT","w",stdout);
    cin>>n>>s;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rm1[i][0]=a[i];
        rm2[i][0]=a[i];
    }
    for (int j=1;j<=MX;j++) {
        for (int i=1;i<=n-(1<<j)+1;i++) {
            rm1[i][j]=min(rm1[i][j-1],rm1[i+(1<<(j-1))][j-1]);
            rm2[i][j]=max(rm2[i][j-1],rm2[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i=2;i<=n;i++) {
        int len=i-start+1,k=__lg(len);
        int mn=min(rm1[start][k],rm1[i-(1<<k)+1][k]);
        int mx=max(rm2[start][k],rm2[i-(1<<k)+1][k]);
        if (mx-mn>s) {
            res++;
            start=i;
        }
    }
    cout<<res;
}

