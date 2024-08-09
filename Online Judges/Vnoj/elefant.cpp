#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
struct ele{
    int w,iq,id;
};
bool cmp(ele x, ele y){
    return x.w<y.w||(x.w==y.w && x.iq<y.iq);
}
ele a[N];
int f[N],d[N],trace[N],l[N],p[N];
int bs(int x){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(d[mid]>x) l=mid+1;
        else r=mid-1;
    }
    return r;
}
void sol(){
    for(int i=1;i<=n;i++) f[i]=1;
    int mx=0;
    trace[1]=0;
    for(int i=1;i<=n;i++){
        int k=bs(a[i].iq);
        trace[i]=p[k];
        f[i]=k+1;
        p[k+1]=i;
        d[k+1]=a[i].iq;
        if(m<f[i]){
            m=f[i];
            mx=i;
        }
    }
    cout<<m<<'\n';
    int i=mx,j=0;
    while (i > 0){
        l[j++] = i;
        i = trace[i];
    }
    for (int i = j - 1; i >= 0; i--) cout << a[l[i]].id <<' ';
}
int main(){
    //freopen("ELEFANTS.INP","r",stdin);
    //freopen("ELEFANTS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].w>>a[i].iq;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    sol();
}
