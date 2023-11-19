#include<bits/stdc++.h>
using namespace std;
const int N=3000;
char a[N+5][N+5];
int n;
bool vis[N+5][N+5];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct dat{
    int u,v,par_u,par_v;
};
stack<dat>st;
void dfs(int u,int v) {
    while (!st.empty()) st.pop();
    st.push({u,v,-1,-1});
    while (!st.empty()) {
        dat t=st.top();
        st.pop();
        for (int i=0;i<4;i++) {
            int x=t.u+dx[i],y=t.v+dy[i];
            if (x==t.par_u&&y==t.par_v) continue;
            if (x>=1&&y>=1&&x<=n&&y<=n&&a[x][y]=='0') {
                if (vis[x][y]) {
                    cout<<"No";
                    exit(0);
                }
                vis[x][y]=true;
                st.push({x,y,t.u,t.v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]=='0'&&!vis[i][j]) {
                vis[i][j]=true;
                dfs(i,j);
            }
        }
    }
    cout<<"Yes";
}
