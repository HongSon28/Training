#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct query{
    char type;
    char l;
    int k;
}q[N+5];
struct Node{
    int child[26];
    vector<int>ask;
}trie[N+5];
int num_node;
int cur=0;
int new_node(char c) {
    num_node++;
    trie[cur].child[c-'a']=num_node;
    //cout<<cur<<' '<<num_node<<' '<<c<<endl;
    return num_node;
}
int n;
string s;
char res[N+5];
int pos[N+5];
void dfs(int u) {
    //cout<<u<<' '<<s<<endl;
    for (auto i:trie[u].ask) res[i]=s[q[i].k];
    for (char c='a';c<='z';c++) {
        if (trie[u].child[c-'a']!=0) {
            s+=c;
            dfs(trie[u].child[c-'a']);
            s.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    int j=0;
    for (int i=1;i<=n;i++)  {
        cin>>q[i].type;
        if (q[i].type=='T') {
            j++;
            cin>>q[i].l;
            if (trie[cur].child[q[i].l-'a']!=0) cur=trie[cur].child[q[i].l-'a'];
            else cur=new_node(q[i].l);
            pos[j]=cur;
        } else if (q[i].type=='U') {
            j++;
            cin>>q[i].k;
            cur=pos[j-q[i].k-1];
            pos[j]=cur;
        } else {
            cin>>q[i].k;
            trie[cur].ask.push_back(i);
        }
        //cout<<cur<<endl;
    }
    dfs(0);
    for (int i=1;i<=n;i++) {
        if (q[i].type=='P') cout<<res[i]<<'\n';
    }
}
