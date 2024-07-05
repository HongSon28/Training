#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,u,v,res,w[N+5],b[N+5];
char a[N+5];
vector<int>adj[N+5];
bool vis[N+5];
void dfs(int s, int par){
    for(auto i:adj[s]){
        if(i==par) continue;
        w[i]+=w[s];
        b[i]+=b[s];
        dfs(i,s);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]=='0'){
            w[i]=1;
            b[i]=0;
        }else{
            b[i]=1;
            w[i]=0;
        }
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++) if(w[i]>b[i]) res++;
    cout<<res;
}