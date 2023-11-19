#include<bits/stdc++.h>
using namespace std;
const int N=2048;
vector<vector<int>>adj(N+5);
int a[N+5][N+5];
int h[N+5];
int x[N*N+5],y[N*N+5];
int t;
int n;
void dfs(int u,int k) {
    for (auto v:adj[u]) {
        if (a[u][v]==1) {
            a[u][v]=k;
            a[v][u]=0;
            h[u]--;
            h[v]--;
            if (k==2) dfs(v,3);
            else dfs(v,2);
            break;
        }
    }
}
int main() {
    cin>>t;
    while (t--) {
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                a[i][j]=0;
        for (int i=1;i<=N;i++) {
            adj[i].clear();
            h[i]=0;
        }
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>x[i]>>y[i];
            adj[x[i]].push_back(y[i]+1024);
            adj[y[i]+1024].push_back(x[i]);
            h[x[i]]++;
            h[y[i]+1024]++;
            a[x[i]][y[i]+1024]=1;
            a[y[i]+1024][x[i]]=1;
        }
        bool flag=true;
        while (flag) {
            flag=false;
            for (int i=1;i<=N;i++) {
                if (h[i]%2==1) {
                    dfs(i,2);
                    flag=true;
                }
            }
            for (int i=1;i<=N;i++) {
                if (h[i]%2==0&&h[i]!=0) {
                    dfs(i,2);
                    flag=true;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            if (a[x[i]][y[i]+1024]==2||a[y[i]+1024][x[i]]==2) cout<<'B';
            else cout<<'R';
        }
        cout<<endl;
    }
}
