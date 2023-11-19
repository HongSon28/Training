#include<bits/stdc++.h>
using namespace std;
set<int>st;
int n,m,t,res;
int main() {
    freopen("DEMPT.INP","r",stdin);
    freopen("DEMPT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
        cin>>t;
        st.insert(t);
    }
    cin>>m;
    while (m--) {
        cin>>t;
        if (st.count(t)!=0) res++;
    }
    cout<<res;
}
