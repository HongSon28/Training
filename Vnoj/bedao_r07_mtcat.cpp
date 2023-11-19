#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int h[N+5];
int j[N+5];
int f[N+5];
stack<int>st;
vector<int>v;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>j[i];
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&h[st.top()]<=h[i]) st.pop();
        if (st.empty()) f[i]=-1;
        else {
            v.push_back(st.top());
            cout<<i<<' '<<v.size()<<endl;
            if (j[i]>v.size()) f[i]=-1;
            else f[i]=h[v[v.size()-j[i]]];

        }
        st.push(i);
    }
    for (int i=1;i<=n;i++) cout<<f[i]<<' ';
}
