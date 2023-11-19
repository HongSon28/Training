#include <bits/stdc++.h>
using namespace std;
int a[5003],f[5003][5003];
bool dau[5003];
vector<int>b;
int main(){
    freopen("Daydx.inp","r",stdin);
    freopen("Daydx.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b.push_back(a[i]);
    }
    reverse(b.begin(),b.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j-1]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    if(f[n][n]<2) cout<<0;
    else{
        cout<<f[n][n]<<'\n';
        int i=n,j=n;
        while(i>0 && j>0){
            if(a[i]==b[j-1]){
                dau[i]=true;
                i--;
                j--;
            }
            else{
                if(f[i][j]==f[i-1][j])
                    i--;
                else
                    j--;
            }
        }
        for(int i=1;i<=n;i++)
        if(dau[i])
            cout<<a[i]<<' ';
    }
}
