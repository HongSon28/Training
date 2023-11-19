#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k;
bool avail[10];
pair<int,int>trace[N+5];
bool vis[N+5];
queue<int>q;
void print() {
    vector<int>res;
    int t=0;
    while (true) {
        pair<int,int>p=trace[t];
        res.push_back(p.second);
        t=p.first;
        if (t==0) break;
    }
    reverse(res.begin(),res.end());
    if (res.size()<9)
        for (auto i:res) cout<<i;
    else
        cout<<res[0]<<res[1]<<res[2]<<"..."<<res[res.size()-3]<<res[res.size()-2]<<res[res.size()-1]<<"("<<res.size()<<" digits)";
}
int main() {
    freopen("MULTIPLE.INP","r",stdin);
    freopen("MULTIPLE.OUT","w",stdout);
    memset(avail,true,sizeof(avail));
    cin>>n>>k;
    for (int i=1;i<=k;i++) {
        int t;
        cin>>t;
        avail[t]=false;
    }
    for (int i=1;i<10;i++) {
        if (avail[i]&&!vis[i%n]) {
            q.push(i%n);
            vis[i%n]=true;
            trace[i%n]={0,i};
        }
    }
    while (!q.empty()) {
        int t=q.front();
        q.pop();
        if (t==0) {
            print();
            return 0;
        }
        for (int i=0;i<10;i++) {
            if (avail[i]&&!vis[(t*10+i)%n]) {
                vis[(t*10+i)%n]=true;
                q.push((t*10+i)%n);
                trace[(t*10+i)%n]={t,i};
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
