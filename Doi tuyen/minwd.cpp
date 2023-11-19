#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
long long bit[N+5],inf=1e18;
pair<long long,long long>p[N+5];
vector<pair<long long, long long>>query[N+5];
vector<long long>v[N+5];
long long res[N+5];
stack<int>st;
void update(int p,long long val) {
    int i=p;
    while (i>0) {
        bit[i]=min(bit[i],val);
        i-=i&(-i);
    }
}
long long get(int p) {
    long long ans=inf;
    int i=p;
    while (i<N) {
        ans=min(ans,bit[i]);
        i+=i&(-i);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    for (int i=0;i<q;i++) {
        long long l,r;
        cin>>l>>r;
        l--;
        query[r].push_back({l,i});
    }
    for (int i=0;i<n;i++) {
        while (!st.empty()&&p[st.top()].second>p[i].second) st.pop();
        if (!st.empty()) v[i].push_back(st.top());
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n-1;i>=0;i--) {
        while (!st.empty()&&p[st.top()].second>p[i].second) st.pop();
        if (!st.empty()) v[st.top()].push_back(i);
        st.push(i);
    }
    for (int i=0;i<=N;i++) bit[i]=inf;
    for (int r=1;r<=n;r++) {
        for (auto l:v[r-1]) {
            long long val=(p[r-1].first-p[l].first)*(p[l].second+p[r-1].second);
            update(l+1,val);
        }
        for (auto [l,id]:query[r]) {
            res[id]=get(l+1);
        }
    }
    for (int i=0;i<q;i++) cout<<res[i]<<'\n';
}
