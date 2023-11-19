#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c1,c2;
int n,m;
pair<int,int>p[N+5];
struct dat{
    int time,price,id;
    bool operator < (const dat &other) const {
        return time<other.time;
    }
};
vector<dat>vc;
bool used[N+5];
map<int,int>mp;
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c1>>c2;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].second>>p[i].first;
    sort(p+1,p+1+n);
    cin>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        vc.push_back({u,c1,i});
        vc.push_back({v,c2,i});
    }
    sort(vc.begin(),vc.end());
    int pos=1,cur=0;
    for (auto t:vc) {
        while (pos<=n&&p[pos].first<=t.time) {
            cur+=p[pos].second;
            pos++;
        }
        if (used[t.id]) continue;
        if (cur>=t.price) {
            cur-=t.price;
            used[t.id]=true;
            res++;
        }
    }
    cout<<res;
}
