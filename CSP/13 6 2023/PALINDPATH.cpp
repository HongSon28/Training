#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<pair<int,char>>>v(21);
bool vis[21][21];
int res=1e9;
struct dat{
    int l,r,cnt;
};
void bfs() {
    queue<dat>q;
    q.push({1,2,0});
    vis[1][2]=true;
    while (!q.empty()) {
        int l=q.front().l,r=q.front().r,cnt=q.front().cnt;
        q.pop();
        if (l==r) {
            res=min(res,cnt);
            //cout<<l<<' '<<r<<' '<<cnt<<endl;
            continue;
        }
        for (auto i:v[l]) {
            if (i.first==r) {
               // cout<<l<<' '<<r<<' '<<cnt+1<<endl;
                res=min(res,cnt+1);
                continue;
            }
        }
        for (auto i:v[l]) {
            for (auto j:v[r]) {
                if (i.second==j.second&&!vis[i.first][j.first]) {
                    vis[i.first][j.first]=true;
                    q.push({i.first,j.first,cnt+2});
                }
            }
        }
    }
}
int main() {
    freopen("PALINDPATH.INP","r",stdin);
    freopen("PALINDPATH.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int a,b;
        char c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    bfs();
    if (res==1e9) cout<<-1;
    else cout<<res;
}
