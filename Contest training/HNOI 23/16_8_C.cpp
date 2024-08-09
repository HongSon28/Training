#include<bits/stdc++.h>
using namespace std;
set<string>dict;
int n,q;
string s;
const int N=500;
bool dp[N+5];
int start[N+5];
void solve() {
    memset(start,0,sizeof(start));
    int m=s.size();
    for (int i=1;i<=m;i++) dp[i]=false;
    dp[0]=true;
    s=' '+s;
    for (int i=1;i<=m;i++) {
        string cur;
        for (int l=i;l>=1;l--) {
            cur=s[l]+cur;
            if (dict.count(cur)!=0) {
                if (dp[l-1]) {
                    dp[i]=true;
                    start[i]=l;
                    break;
                }
            }
        }
    }
    if (!dp[m]) cout<<-1<<'\n';
    else {
        int cur=m;
        vector<string>res;
        while (cur>0) {
            string temp=s.substr(start[cur],cur-start[cur]+1);
            res.push_back(temp);
            cur=start[cur]-1;
        }
        reverse(res.begin(),res.end());
        for (auto i:res) cout<<i<<' ';
        cout<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
        string temp;
        cin>>temp;
        dict.insert(temp);
    }
    cin>>q;
    while (q--) {
        cin>>s;
        solve();
    }
}
