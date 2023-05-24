#include<bits/stdc++.h>
using namespace std;
bool v[1001];
int n,m,s,t;
struct vt {
    int c,cnt;
};
vector<vector<int>>vc(1001);
int bfs() {
    v[s]=true;
    queue<vt>q;
    q.push({s,0});
    while (q.empty()==false) {
        vt temp=q.front();
        q.pop();
        if (temp.c==t)
            return temp.cnt;
        for (int i=0;i<vc[temp.c].size();i++) {
            if (v[vc[temp.c][i]]==false) {
                v[vc[temp.c][i]]=true;
                q.push({vc[temp.c][i],temp.cnt+1});
            }
        }
    }
    return -1;
}
int main() {
    memset(v,false,sizeof(v));
    cin>>n>>m>>s>>t;
    int l,r;
    for (int i=0;i<m;i++) {
        cin>>l>>r;
        if (l!=r) {
            vc[l].push_back(r);
            vc[r].push_back(l);
        }
    }
    cout<<bfs();
}
