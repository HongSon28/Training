#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n;
string s;
int deg[N+5],ans[N+5];
vector<int>topo;
vector<vector<int>>adj(N+5);
priority_queue<int,vector<int>,greater<int>>q;
int main() {
    freopen("XEPVIEC.INP","r",stdin);
    freopen("XEPVIEC.OUT","w",stdout);
    cin>>n;
    while (getline(cin,s)) {
        stringstream ss(s);
        string num1,num2;
        ss>>num1;
        while (ss>>num2) {
            adj[stoi(num1)].push_back(stoi(num2));
            deg[stoi(num2)]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (deg[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int u=q.top();
        q.pop();
        topo.push_back(u);
        for (auto v:adj[u]) {
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    if (topo.size()<n) {
        cout<<0;
        return 0;
    }
    int cnt=0;
    for (auto x:topo) cout<<x<<' ';
}
