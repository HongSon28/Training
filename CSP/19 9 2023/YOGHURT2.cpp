#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N+5],b[N+5];
long long cur;
priority_queue<pair<long long,int>>pq;
vector<int>res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("YOGHURT2.INP","r",stdin);
    freopen("YOGHURT2.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) {
        cur+=a[i];
        if (cur<b[i]) {
            if (!pq.empty()&&pq.top().first>b[i]) {
                cur+=pq.top().first;
                pq.pop();
                pq.push({b[i],i});
                cur-=b[i];
            }
        } else {
            pq.push({b[i],i});
            cur-=b[i];
        }
    }
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for (auto i:res) cout<<i<<' ';
}
