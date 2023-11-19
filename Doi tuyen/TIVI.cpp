#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,k;
vector<vector<int>>v(N+5);
bool vis[(1<<(N+2))+5];
queue<pair<int,int>>q;
int target;
int main() {
    cin>>n>>k;
    target|=(1<<k);
    for (int i=1;i<=n;i++) {
        int s;
        cin>>s;
        v[i].push_back(s);
        for (int j=1;j<=s;j++) {
            int t;
            cin>>t;
            v[i].push_back(t);
        }
    }
    int bit=0;
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        if (t==1) bit|=(1<<i);
    }
    vis[bit]=true;
    q.push({bit,0});
    while (!q.empty()) {
        pair<int,int> t=q.front();
        q.pop();
        if (t.first==target){
            cout<<t.second;
            return 0;
        }
        for (int i=1;i<=n;i++) {
            int temp=t.first;
            for (int j=1;j<v[i].size();j++) {
                temp&=~(1<<v[i][j]);
            }
            temp|=(1<<i);
            if (!vis[temp]) {
                vis[temp]=true;
                q.push({temp,t.second+1});
            }
        }
    }
    cout<<-1;
}
