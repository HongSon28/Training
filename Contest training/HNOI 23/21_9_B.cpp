#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long dp[N+5];
long long mod=1e9+7;
string s;
struct Trie{
    struct Node{
        int child[26];
        int exist,cnt;
    } node[N+5];
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
        reverse(s.begin(),s.end());
        trie.add_string(s);
    }
    cin>>s;
    n=s.size();
    s=' '+s;
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        int pos=0;
        for (int j=i;j>=min(1,j-100);j--) {
            int t=s[j]-'a';
            if (trie.node[pos].child[t]==-1) break;
            pos=trie.node[pos].child[t];
            if (trie.node[pos].exist!=0) dp[i]=(dp[i]+dp[j-1])%mod;
        }
        //cout<<dp[i]<<endl;
    }
    cout<<dp[n];
}
