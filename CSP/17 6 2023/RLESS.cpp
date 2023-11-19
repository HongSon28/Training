#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int mn=INT_MAX,n;
int a[N+5];
stack<int>st;
int main() {
    freopen("RLESS.INP","r",stdin);
    freopen("RLESS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (st.empty()) cout<<-1<<' ';
        else cout<<st.top()<<' ';
        st.push(i);
    }
}
