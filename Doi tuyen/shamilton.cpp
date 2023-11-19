#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int adj[26][26];
vector<int>id[26][26],res;
void dfs(int u) {
    for (int v=0;v<26;v++) {
        if (adj[u][v]) {
            adj[u][v]--;
            dfs(v);
        }
    }
    res.push_back(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s;
        int u=s.front()-'a';
        int v=s.back()-'a';
        id[u][v].push_back(i);
        adj[u][v]++;
    }
    dfs(s.front()-'a');
    for (int u=0;u<26;u++) {
        for (int v=0;v<26;v++) {
            if (adj[u][v]) {
                cout<<-1;
                return 0;
            }
        }
    }
    for (int i=res.size()-1;i>=1;i--) {
        int u=res[i],v=res[i-1];
        cout<<id[u][v].back()<<' ';
        id[u][v].pop_back();
    }
}
