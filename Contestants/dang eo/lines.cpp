#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],b[N];
int l[N],d[N],trace[N],f[N],pos[N],p[N];
vector<pair<int,int>>vp;
int bs(int x){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(d[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return r;
}
void sol(){
    for(int i=1;i<=n;i++) f[i]=1;
    int imax=0;
    for(int i=1;i<=n;i++){
        int k=bs(vp[i].first);
        trace[i]=p[k];
        f[i]=k+1;
        d[k+1]=vp[i].first;
        p[k+1]=i;
        if(m<f[i]){
            m=f[i];
            imax=i;
        }
        //cout<<f[i]<<' ';
    }
    cout<<m<<'\n';
    int i=imax,j=0;
    while(i>0){
        l[j++]=i;
        i=trace[i];
    }
    for(int i=j-1;i>=0;i--) {
        cout<<vp[l[i]].second<<' ';
    }
}
int main(){
    freopen("LINES.INP","r",stdin);
    freopen("LINES.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    vp.push_back({0,0});
    for(int i=1;i<=n;i++){
        cin>>b[i];
        vp.push_back(make_pair(pos[b[i]],b[i]));
    }
    sol();
}
