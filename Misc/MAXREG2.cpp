#include<bits/stdc++.h>
using namespace std;
int n,m,c[15005][1505],res;
char a[15005][1505];
int main(){
    freopen("maxreg.inp","r",stdin);
    freopen("maxreg.ans","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            c[i][j]=c[i-1][j]+(a[i][j]-'0');
        }
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int cnt=0;
            for(int j=1;j<=m;j++){
                if(c[r][j]-c[l-1][j]==r-l+1) cnt++;
            }
            res=max(res,cnt*(r-l+1));
        }
    }
    cout<<res;
}
