#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,t,a[105],res;
bool f[2][N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    f[0][0]=1;
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)
            if(i>=a[j] && f[0][i-a[j]]) f[0][i]=1;
    for(int i=1;i<=t;i++) f[1][i/2]|=f[0][i];
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)
            if(i>=a[j] && f[1][i-a[j]]) f[1][i]=1;
    for(int i=1;i<=t;i++) if(f[0][i]||f[1][i]) res=max(res,i);
    cout<<res;
}