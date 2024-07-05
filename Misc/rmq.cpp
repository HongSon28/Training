#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int MX=20;
int n,q,a[N+5],rm[N+5][MX+1],id[N+5][MX+1];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        rm[i][0]=a[i];
        id[i][0]=i;
    }
    for(int j=1;j<=MX;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            if(rm[i][j-1]<=rm[i+(1<<(j-1))][j-1]){
                rm[i][j]=rm[i][j-1];
                id[i][j]=id[i][j-1];
            }else{
                rm[i][j]=rm[i+(1<<(j-1))][j-1];
                id[i][j]=id[i+(1<<(j-1))][j-1];
            }
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int k=__lg(r-l+1);
        if(rm[l][k]<=rm[r-(1<<k)+1][k]) cout<<id[l][k]<<'\n';
        else cout<<id[r-(1<<k)+1][k]<<'\n';
    }
}