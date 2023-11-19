#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>vis;
queue<pair<string,int>>q;
string target="1238004765";
string change1(string s) {
    string res;
    res.resize(10);
    res[0]=s[3];
    res[1]=s[0];
    res[2]=s[2];
    res[3]=s[7];
    res[4]=s[4];
    res[5]=s[1];
    res[6]=s[6];
    res[7]=s[8];
    res[8]=s[5];
    res[9]=s[9];
    return res;
}
string change2(string s) {
    string res;
    res.resize(10);
    res[0]=s[0];
    res[1]=s[4];
    res[2]=s[1];
    res[3]=s[3];
    res[4]=s[8];
    res[5]=s[5];
    res[6]=s[2];
    res[7]=s[7];
    res[8]=s[9];
    res[9]=s[6];
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    for (int i=1;i<=10;i++) {
        int t;
        cin>>t;
        s+=to_string(t);
    }
    vis[s]=true;
    q.push({s,0});
    while (!q.empty()) {
        pair<string,int>t=q.front();
        q.pop();
        if (t.first==target) {
            cout<<t.second;
            return 0;
        }
        string s1=change1(t.first);
        if (!vis[s1]) {
            vis[s1]=true;
            q.push({s1,t.second+1});
        }
        string s2=change2(t.first);
        if (!vis[s2]) {
            vis[s2]=true;
            q.push({s2,t.second+1});
        }
    }
    cout<<-1;
}
