#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,b;
long long a[N+5];
long long l[N+5],r[N+5];
long long res;
int main() {
    freopen("NUMMAX.INP","r",stdin);
    freopen("NUMMAX.OUT","w",stdout);
    cin>>n>>b;
    for (int i=1;i<=n;i++) cin>>a[i];
    stack<long long>st;
    for (long long i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if (!st.empty()) l[i]=st.top();
        else l[i]=0;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (long long i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]<a[i]) st.pop();
        if (!st.empty()) r[i]=st.top();
        else r[i]=n+1;
        st.push(i);
    }
//    for (int i=1;i<=n;i++) cout<<l[i]<<' ';
//    cout<<endl;
//    for (int i=1;i<=n;i++) cout<<r[i]<<' ';
//    cout<<endl;
    for (long long i=1;i<=n;i++) {
        if (a[i]==b) {
            long long left=i-l[i],right=r[i]-i;
            res+=left*right;
        }
    }
    cout<<res;
}
