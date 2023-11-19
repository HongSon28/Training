#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5];
long long l_min[N+5],r_min[N+5],l_max[N+5],r_max[N+5];
stack<int>st;
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
        if (st.empty()) l_min[i]=1;
        else l_min[i]=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]>a[i]) st.pop();
        if (st.empty()) r_min[i]=n;
        else r_min[i]=st.top()-1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if (st.empty()) l_max[i]=1;
        else l_max[i]=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]<a[i]) st.pop();
        if (st.empty()) r_max[i]=n;
        else r_max[i]=st.top()-1;
        st.push(i);
    }
    for (int i=1;i<=n;i++) {
        res-=a[i]*(i-l_min[i]+1)*(r_min[i]-i+1)-a[i];
        res+=a[i]*(i-l_max[i]+1)*(r_max[i]-i+1)-a[i];
        //cout<<l_min[i]<<' '<<r_min[i]<<' '<<l_max[i]<<' '<<r_max[i]<<' '<<res<<endl;
    }
    cout<<res;
}
