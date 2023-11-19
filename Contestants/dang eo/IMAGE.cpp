
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1030][1030],s[1030][1030];
int f(int u, int l, int d, int r){
     int sum=s[d][r]-s[u-1][r]-s[d][l-1]+s[u-1][l-1];
     if(sum==(r-l+1)*(d-u+1) || sum==0) return 2;
     else {
        int t1=1+f(u,l,(u+d)/2,(l+r)/2);
        int t2=f(u,(l+r)/2+1,(u+d)/2,r);
        int t3=f((u+d)/2+1,l,d,(r+l)/2);
        int t4=f((u+d)/2+1,(l+r)/2+1,d,r);
        return t1+t2+t3+t4;
     }
}
int main(){
    freopen("IMAGE.INP","r",stdin);
    freopen("IMAGE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++){
            cin>>a[i][j];
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    cout<<f(1,1,1<<n,1<<n);
}
