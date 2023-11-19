#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
const int N=3e4;
int n;
ll a[N+5];
int main() {
    cin>>t;
    while (t--) {
        stack<ll>st;
        cin>>n;
        ll l[n+1],r[n+1];
        for (int i=1;i<=n;i++) cin>>a[i];
        for (ll i=1;i<=n;i++) {
            while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
            if (st.empty()) l[i]=1;
            else l[i]=st.top()+1;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (ll i=n;i>=1;i--) {
            while (!st.empty()&&a[st.top()]>=a[i]) st.pop();
            if (st.empty()) r[i]=n;
            else r[i]=st.top()-1;
            st.push(i);
        }
        ll res=0,rl,rr;
        for (int i=1;i<=n;i++) {
            ll left=l[i],right=r[i];
            int sum=a[i]*(right-left+1);
            if (sum>res) {
                res=sum;
                rl=left,rr=right;
            }
        }
        cout<<res<<' '<<rl<<' '<<rr<<endl;
    }
}
