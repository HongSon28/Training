#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct Trie{
    struct Node{
        int child[2];
        int exist,cnt;
    } node[N*32+5];
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
    void add_number(int x) {
        int pos=0;
        for (int bit=30;bit>=0;bit--) {
            int c=(x>>bit)&1;
            if (node[pos].child[c]==-1) node[pos].child[c]=new_node();
            pos=node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
}trie;
int n;
int a[N+5];
int res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        trie.add_number(a[i]);
    }
    for (int i=1;i<=n;i++) {
        int cur=0;
        int pos=0;
        for (int bit=30;bit>=0;bit--) {
            if (a[i]>>bit&1) {
                if (trie.node[pos].child[0]!=-1) {
                    pos=trie.node[pos].child[0];
                    cur|=(1<<bit);
                } else pos=trie.node[pos].child[1];
            } else {
                if (trie.node[pos].child[1]!=-1) {
                    pos=trie.node[pos].child[1];
                    cur|=(1<<bit);
                } else pos=trie.node[pos].child[0];
            }
        }
        res=max(res,cur);
    }
    cout<<res;
}
