#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int l[N+5],r[N+5];
stack<int>st;
int res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (!st.empty()) l[i]=st.top()+1;
        else l[i]=1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (!st.empty()) r[i]=st.top()-1;
        else r[i]=n;
        st.push(i);
    }
    for (int i=1;i<=n;i++) {
        if(a[i]<=r[i]-l[i]+1) res=max(res,a[i]);
    }
    cout<<res;
}
