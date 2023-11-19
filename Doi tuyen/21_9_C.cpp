#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
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
int n,q;
string s;
int res[N+5];
vector<pair<string,pair<int,int>>>v;
bool comp(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b) {
    return a.second.first<b.second.first;
}
map<string,int>t;
vector<string>vv;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s;
        t[s]=i;
        vv.push_back(s);
    }
    cin>>q;
    for (int i=0;i<q;i++) {
        cin>>s;
        int id=t[s];
        if (id==0) id=n;
        v.push_back({s,{id-1,i}});
    }
    sort(v.begin(),v.end(),comp);
    int pos=0,x;
    for (int i=0;i<q;i++) {
        int ans=0;
        //cout<<v[i].second.first<<' '<<v[i].second.second<<endl;
        while (pos<=v[i].second.first) {
            trie.add_string(vv[pos]);
            pos++;
        }
        int x=0;
        ans+=v[i].second.first+1;
        for (auto f:v[i].first) {
            int c=f-'a';
            if (trie.node[x].child[c]==-1) break;
            x=trie.node[x].child[c];
            ans+=trie.node[x].cnt;
        }
        res[v[i].second.second]=ans;
    }
    for (int i=0;i<q;i++) cout<<res[i]<<'\n';
}
