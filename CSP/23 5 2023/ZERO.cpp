#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
bool vis[N+5];
vector<int>res;
void dfs(int s) {
    if (s!=0) {
        for (int i=1;i*i<=s;i++) {
            if (s%i==0) {
                int j=s/i;
                int t=(i-1)*(j+1);
                if (!vis[t]) {
                    vis[t]=true;
                    res.push_back(t);
                    dfs(t);
                }
            }
        }
    }
}
int main() {
    freopen("ZERO.INP","r",stdin);
    freopen("ZERO.OUT","w",stdout);
    cin>>n;
    vis[n]=true;
    dfs(n);
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for (auto i:res) cout<<i<<' ';
}
