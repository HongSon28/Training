#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int>st;
    map<int,int>mp;
    int n;
    cin>>n;
    int x,res=0;
    for (int i=0;i<n;i++) {
        cin>>x;
        while (st.empty()==false&&x>st.top()) {
            mp[st.top()]--;
            st.pop();
            res++;
        }
        if (st.empty()==false)
            res+=x==st.top()? mp[x] + (st.size()>mp[x]):1;
        st.push(x);
        mp[x]++;
    }
    cout<<res;
}
