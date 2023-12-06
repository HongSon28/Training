#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<int>st;
    for (int i=0;i<n;i++) {
        int t;
        cin>>t;
        if (st.count(t)==0) {
            cout<<t<<' ';
            st.insert(t);
        }
    }
}
