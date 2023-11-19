#include<bits/stdc++.h>
using namespace std;
int m,n,cnt;
int qua[int(1e6)+2],khach[int(1e6)+2],start[int(1e6)+2],c[int(1e6)+2];
int main(){
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++) cin>>qua[i];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>khach[i];
    for(int i=1;i<=n;i++) start[khach[i]]=khach[i];
    for(int i=1;i<=n;i++){
        int dem=khach[i];
        for(int j=start[khach[i]];j<=1e6;j+=khach[i]){
            if(c[j]==0){
                c[j]++;
                dem--;
            }
            start[khach[i]]=j+khach[i];
            if(dem<=0) break;
        }
    }
    for(int i=1;i<=m;i++)
        if(c[qua[i]]!=0) cnt++;
    cout<<cnt;
}

