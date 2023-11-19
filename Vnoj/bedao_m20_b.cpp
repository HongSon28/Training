#include<bits/stdc++.h>
using namespace std;
struct query{
    long long l,r,x;
};
stack<query>st;
long long type,L,R,l,r,x,n,q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    while (q--) {
        cin>>type;
        if (type==1) {
            cin>>l>>r>>x;
            st.push({l,r,x});
        } else {
            long long ans=0;
            cin>>l>>r;
            while (!st.empty()) {
                query t=st.top();
                st.pop();
                L=max(l,t.l);
                R=min(r,t.r);
                if (L>R) continue;
                if ((R-L+1)%2==1) ans^=t.x;
            }
            cout<<ans<<'\n';
        }
    }
}
