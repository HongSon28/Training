#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct dat{
    int i,j,d;
};
int n,m;
int s,t;
int i,j;
int temp;
int par[N+5];
vector<dat>res;
int k,v;
int conv1(int x,int y) {
    return (x-1)*m+y;
}
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CIRCUIT.INP","r",stdin);
    freopen("CIRCUIT.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cin>>temp;
            if (temp==1) {
                s=findroot(conv1(i,j));
                t=findroot(conv1(i+1,j));
                if(s!=t)
                    Union(s,t);
            } else if (temp==2) {
                s=findroot(conv1(i,j));
                t=findroot(conv1(i,j+1));
                if(s!=t)
                    Union(s,t);
            } else if (temp==3) {
                s=findroot(conv1(i,j));
                t=findroot(conv1(i+1,j));
                if(s!=t)
                    Union(s,t);
                s=findroot(conv1(i,j));
                t=findroot(conv1(i,j+1));
                if(s!=t)
                    Union(s,t);
            }
        }
    }
    for (i=1;i<n;i++) {
        for (j=1;j<=m;j++) {
            s=findroot(conv1(i,j));
            t=findroot(conv1(i+1,j));
            if (s!=t) {
                Union(s,t);
                res.push_back({i,j,1});
                k++;
                v++;
            }
        }
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<m;j++) {
            s=findroot(conv1(i,j));
            t=findroot(conv1(i,j+1));
            if (s!=t) {
                Union(s,t);
                res.push_back({i,j,2});
                k++;
                v+=2;
            }
        }
    }
    cout<<k<<' '<<v<<endl;
    for (auto i:res) cout<<i.i<<' '<<i.j<<' '<<i.d<<endl;
}
