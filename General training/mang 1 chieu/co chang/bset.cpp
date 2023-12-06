#include<bits/stdc++.h>
using namespace std;
int main() {
    set <int> st;
    set <int> st1;
    set <int> st2;
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i=0;i<n;i++) {
        cin>>a[i];
        st.insert(a[i]);
        st1.insert(a[i]);
    }
    for (int i=0;i<m;i++) {
        cin>>b[i];
        st.insert(b[i]);
        st2.insert(b[i]);
    }
    cout<<st.size()<<" "<<st1.size()+st2.size()-st.size();
}
