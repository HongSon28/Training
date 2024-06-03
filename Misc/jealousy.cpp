#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,a[N+5],b[N+5],f[N+5][3][3],res;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            if(j==1) f[i][j][0]=max({f[i-1][j-1][0],f[i-1][0][1],f[i-1][0][2]})+a[i];
            else if(j==2) f[i][j][0]=f[i-1][j-1][0]+a[i];
        }
        for(int k=1;k<=2;k++){
            if(k==1) f[i][0][k]=max({f[i-1][0][k-1],f[i-1][1][0],f[i-1][2][0]})+b[i];
            else if(k==2) f[i][0][k]=f[i-1][0][k-1]+b[i];
        }
    }
    for(int j=0;j<=2;j++)
        for(int k=0;k<=2;k++) res=max(res,f[n][j][k]);
    cout<<res;
}