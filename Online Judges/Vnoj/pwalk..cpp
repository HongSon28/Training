#include<bits/stdc++.h>
using namespace std;
int n,q;
int p1,p2;
vector<vector<pair<int,int>>>v(1001);
bool vis[1001];
void dfs(int u,int cnt) {
    if (u==p2) {
        cout<<cnt<<endl;
        return;
    }
    for (auto i:v[u]) {
        if (vis[i.first]==false) {
            vis[i.first]=true;
            dfs(i.first,cnt+i.second);
            vis[i.first]=false;
        }
    }
}
int main() {
    cin>>n>>q;
    for (int i=1;i<n;i++) {
        int a,b,l;
        cin>>a>>b>>l;
        v[a].push_back(make_pair(b,l));
        v[b].push_back(make_pair(a,l));
    }
    while (q--) {
        cin>>p1>>p2;
        memset(vis,false,sizeof(vis));
        vis[p1]=true;
        dfs(p1,0);
    }
}
