#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],c[N+5];
int rk[N+5];
vector<int>v,b;
stack<int>st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("STACK.INP","r",stdin);
    freopen("STACK.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]++;
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for (int i=0;i<v.size();i++) rk[v[i]]=i+1;
    int cur=1;
    for (int i=1;i<=n;i++) {
        st.push(a[i]);
        while (!st.empty()&&rk[st.top()]==cur) {
            c[st.top()]--;
            b.push_back(st.top());
            if (c[st.top()]==0) cur++;
            st.pop();
        }
    }
    while (!st.empty()) {
        b.push_back(st.top());
        st.pop();
    }
    for (auto x:b) cout<<x<<' ';
}
