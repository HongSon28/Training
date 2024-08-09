#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int mx;
int res;
string s;
int len;
int dp[N+5];
struct Trie{
    struct Node{
        int child[26];
        int exist, cnt;
    } nodes[N+5];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }
    void add_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) {
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
    bool find_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }
};
Trie tri;
int main() {
    freopen("LAUGH.INP","r",stdin);
    freopen("LAUGH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    len=s.length();
    s=' '+s;
    for (int i=0;i<n;i++) {
        string t;
        cin>>t;
        int lent=t.length();
        mx=max(mx,lent);
        tri.add_string(t);
    }
    for (int i=1;i<=len;i++) {
        string t;
        for (int j=i;j<i+mx;j++) {
            t+=s[j];
            //cout<<i<<' '<<j<<' '<<t<<endl;
            if (tri.find_string(t)) {
                dp[j]=max(dp[j],dp[i-1]+j-i+1);
                res=max(res,dp[j]);
            }
            //cout<<dp[i]<<' ';
        }
    }
    //for (int i=1;i<=len;i++) cout<<dp[i]<<' ';
    cout<<res;
}
