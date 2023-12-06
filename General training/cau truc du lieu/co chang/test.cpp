#include <bits/stdc++.h>
using namespace std;
struct vitri{
    int a,cnt;
};
int m,n,s,t,u,v;
bool vis[1001];
vector<vector<int>>q(1001);
int bfs(){
    fill(vis,vis+1001,false);
    vis[s]=true;
    queue<vitri>p;
    p.push({s,0});
    cout<<p.front().a<<endl;
    while(p.empty()==false){
        vitri x=p.front();
        p.pop();
        if(x.a==t) return x.cnt;
        for(int j=0;j<q[x.a].size();j++)
            if(!vis[q[x.a][j]]){
                vis[q[x.a][j]]=true;
                p.push({q[x.a][j],x.cnt+1});
            }
    }
    return -1;
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        if(u!=v){
        q[u].push_back(v);
        q[v].push_back(u);}}
    cout<<bfs;
}
