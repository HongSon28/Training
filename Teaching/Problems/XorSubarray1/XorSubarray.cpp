#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int n;
int x[N+5],s[N+5];
set<int>st;
int main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>n;
    st.insert(0);
    for (int i=1;i<=n;i++) {
        cin>>x[i];
        s[i]=(s[i-1]^x[i]);
        if (st.count(s[i])!=0) {
            cout<<"YES";
            return 0;
        }
        st.insert(s[i]);
    }
    cout<<"NO";
}
