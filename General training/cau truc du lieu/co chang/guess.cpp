#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    set<int>st;
    int t;
    cin>>t;
    st.insert(t);
    for (int i=1;i<n;i++) {
        cin>>t;
        int mn=t-m;
        auto it= st.upper_bound(mn);
        int s=*it;
        if (it!=st.end()&&st.count(s)!=0) {
            if (abs(s-t)<m&&s!=t){
                cout<<i+1;
                return 0;
            }
        }
        st.insert(t);
    }
    cout<<-1;
}
