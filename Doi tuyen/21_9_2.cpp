#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
string s;
struct Trie{
    struct Node{
        int child[26];
        int exist,cnt;
    } node[26*N+5];
    int cur;
    Trie():cur(0) {
        memset(node[cur].child,-1,sizeof(node[cur].child));
        node[cur].exist=node[cur].cnt=0;
    };
    int new_node(){
        cur++;
        memset(node[cur].child,-1,sizeof(node[cur].child));
        node[cur].exist=node[cur].cnt=0;
        return cur;
    }
    void add_string(string s) {
        int pos=0;
        for (auto f:s) {
            int c=f-'a';
            if (node[pos].child[c]==-1) node[pos].child[c]=new_node();
            pos=node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
    bool find_string(string s) {
        int pos=0;
        for (auto f:s) {
            int c=f-'a';
            if (node[pos].child[c]==-1) return false;
            pos=node[pos].child[c];
        }
        return (node[pos].exist!=0);
    }
}trie;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
        cin>>s;
        trie.add_string(s);
    }
    cin>>n;
    while (n--) {
        cin>>s;
        cout<<trie.find_string(s)<<'\n';
    }
}

