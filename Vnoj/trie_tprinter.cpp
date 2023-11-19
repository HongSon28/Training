#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct trie{
    struct node{
        int child[26];
        int cnt,exist;
        bool mx;
    }nodes[N+5];
    int cur;
    trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[0].child));
        nodes[0].exist = nodes[0].cnt = 0;
        nodes[0].mx=false;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        nodes[cur].mx=false;
        return cur;
    }

    void add_string(string s) {
        int pos=0;
        for (auto f:s) {
            int c=f-'a';
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos=nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
} Trie;
int n;
string s[N+5];
string res,t;
void dfs(int u) {
    //cout<<u<<endl;
    for (char c='a';c<='z';c++) {
        if (Trie.nodes[u].child[c-'a']==-1) continue;
        int next=Trie.nodes[u].child[c-'a'];
        if (Trie.nodes[next].cnt==0) continue;
        if (Trie.nodes[next].mx) continue;
        res+=c;
        for (int i=1;i<=Trie.nodes[next].exist;i++) res+='P';
        dfs(next);
        res+='-';
    }
    for (char c='a';c<='z';c++) {
        if (Trie.nodes[u].child[c-'a']==-1) continue;
        int next=Trie.nodes[u].child[c-'a'];
        if (Trie.nodes[next].cnt==0) continue;
        if (!Trie.nodes[next].mx) continue;
        res+=c;
        for (int i=1;i<=Trie.nodes[next].exist;i++) res+='P';
        dfs(next);
        res+='-';
    }
}
int mx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        if (s[i].size()>mx) {
            mx=s[i].size();
            t=s[i];
        }
        Trie.add_string(s[i]);
    }
    int pos=0;
    for (auto f:t) {
        int c=f-'a';
        pos=Trie.nodes[pos].child[c];
        Trie.nodes[pos].mx=true;
    }
    dfs(0);
    while (res.back()=='-') res.pop_back();
    cout<<res.size()<<'\n'<<res;
}
