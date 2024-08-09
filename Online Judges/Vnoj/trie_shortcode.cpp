#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
string st;
struct Trie{
    struct node{
        int child[26];
        int exist;
    }nodes[N+5];
    int cur=0;
    Trie():cur(0) {
        memset(nodes[0].child,-1,sizeof(nodes[0].child));
        nodes[0].exist=0;
    }
    int add_node() {
        cur++;
        memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
        nodes[cur].exist=0;
        return cur;
    }
    void add_string (string s) {
        int pos=0;
        for (auto f:s) {
            int c=f-'a';
            if (nodes[pos].child[c]==-1) nodes[pos].child[c]=add_node();
            pos=nodes[pos].child[c];
        }
        nodes[pos].exist=1;
    }
} trie;
int sz[N+5],d[N+5],sum[N+5];
multiset<int>s[N+5];
void dfs(int u) {
    if (trie.nodes[u].exist==1) {
        sz[u]=1;
        s[u].insert(d[u]);
    }
    for (int c=0;c<26;c++) {
        if (trie.nodes[u].child[c]==-1) continue;
        int v=trie.nodes[u].child[c];
        d[v]=d[u]+1;
        dfs(v);
        sz[u]+=sz[v];
        sum[u]+=sum[v]+sz[v];
        if (s[u].size()<s[v].size()) swap(s[u],s[v]);
        for (auto t:s[v]) s[u].insert(t);
        s[v].clear();
    }
    if (trie.nodes[u].exist==0&&s[u].size()>0&&u>0) {
        auto it=prev(s[u].end());
        sum[u]-=*it-d[u];
        s[u].erase(it);
        s[u].insert(d[u]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>st;
        trie.add_string(st);
    }
    dfs(0);
    cout<<sum[0];
}
