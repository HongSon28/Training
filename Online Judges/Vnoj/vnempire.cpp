#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
struct planet{
    int x,y,z,id;
};
planet a[N+5];
bool comp_x (planet a,planet b) {
    return a.x<b.x;
}
bool comp_y (planet a,planet b) {
    return a.y<b.y;
}
bool comp_z (planet a,planet b) {
    return a.z<b.z;
}
struct edge{
    int u,v,dis;
    bool operator < (const edge &other){
        return dis<other.dis;
    }
};
vector<edge>edges;
int par[N+5];
int res;
int find_root(int x) {
    if (par[x]<0) return x;
    return par[x]=find_root(par[x]);
}
void Union(int x,int y) {
    if ((x=find_root(x))==(y=find_root(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int main() {
    memset(par,-1,sizeof(par));
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].id=i;
    }
    sort(a+1,a+1+n,comp_x);
    for (int i=1;i<n;i++) {
        edges.push_back({a[i].id,a[i+1].id,min(min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y)),abs(a[i].z-a[i+1].z))});
    }
    sort(a+1,a+1+n,comp_y);
    for (int i=1;i<n;i++) {
        edges.push_back({a[i].id,a[i+1].id,min(min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y)),abs(a[i].z-a[i+1].z))});
    }
    sort(a+1,a+1+n,comp_z);
    for (int i=1;i<n;i++) {
        edges.push_back({a[i].id,a[i+1].id,min(min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y)),abs(a[i].z-a[i+1].z))});
    }
    sort(edges.begin(),edges.end());
    for (int i=0;i<edges.size();i++) {
        if (find_root(edges[i].u)!=find_root(edges[i].v)) {
            Union(edges[i].u,edges[i].v);
            res+=edges[i].dis;
        }
    }
    cout<<res;
}
