#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct dat{
    long long u,v,w;
};
bool comp(dat x, dat y) {
    return x.w<y.w;
}
int n,m;
double res;
int par[N+5];
vector<dat>edge;
pair<int,int>coor[N+5];
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
long long calc(int x,int y) {
    return (coor[x].first-coor[y].first)*(coor[x].first-coor[y].first)+(coor[x].second-coor[y].second)*(coor[x].second-coor[y].second);
}
int main() {
    freopen("BAI5.INP","r",stdin);
    freopen("BAI5.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n;
    for (int i=1;i<=n;i++) cin>>coor[i].first>>coor[i].second;
    cin>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    for (int i=1;i<n;i++){
        for (int j=i+1;j<=n;j++) {
            edge.push_back({i,j,calc(i,j)});
        }
    }
    sort(edge.begin(),edge.end(),comp);
    for (auto i:edge) {
        int r=findroot(i.u);
        int s=findroot(i.v);
        if (r!=s) {
            Union(r,s);
            double temp=calc(i.u,i.v);
            res+=sqrt(temp);
        }
    }
    cout<<(long long)res;
}
/*5
1 5
0 0
3 2
4 5
5 1
1
1 4
*/
