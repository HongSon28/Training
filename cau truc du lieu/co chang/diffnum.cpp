#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int temp;
    set<int> st;
    for (int i=0;i<n;i++) {
        cin>>temp;
        st.insert(temp);
    }
    cout<<st.size();
}
