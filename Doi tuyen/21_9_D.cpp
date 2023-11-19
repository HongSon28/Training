#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string res;
int n;
string s;
string maxstr(string x,string y){
    if (x.size()>y.size()) return x;
    if (x.size()<y.size()) return y;
    return min(x,y);
}
struct Trie{
    struct Node{
        int child[26];
        string str;
    } node[N+5];
    int cur;
    Trie():cur(0) {
        memset(node[cur].child,-1,sizeof(node[cur].child));
        node[cur].str="";
    };
    int new_node(){
        cur++;
        memset(node[cur].child,-1,sizeof(node[cur].child));
        node[cur].str="";
        return cur;
    }
    void add_string(string s) {
        int pos=0;
        string t=s;
        sort(t.begin(),t.end());
        for (auto f:t) {
            int c=f-'a';
            if (node[pos].child[c]==-1) node[pos].child[c]=new_node();
            pos=node[pos].child[c];
        }
        node[pos].str=maxstr(node[pos].str,s);
    }
}trie;
void solve(int pos,int last) {
     res=maxstr(res,trie.node[pos].str);
     for (int i=last;i<s.size();i++) {
         int c=s[i]-'a';
         if (trie.node[pos].child[c]!=-1) solve(trie.node[pos].child[c],i+1);
     }
}
int main() {
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
        res="";
        sort(s.begin(),s.end());
        solve(0,0);
        if (res.empty()) cout<<"IMPOSSIBLE"<<'\n';
        else cout<<res<<'\n';
    }
}
