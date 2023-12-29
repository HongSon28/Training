#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long m[N+5],l[N+5],r[N+5],mx,pos;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>m[i];
    stack<int>st;
    for (int i=1;i<=n;i++) {
    	while (!st.empty()&&m[i]<=m[st.top()]) st.pop();
    	if (st.empty()) l[i]=m[i]*i;
    	else l[i]=l[st.top()]+(i-st.top())*m[i];
    	st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
    	while (!st.empty()&&m[i]<=m[st.top()]) st.pop();
    	if (st.empty()) r[i]=m[i]*(n-i+1);
    	else r[i]=r[st.top()]+(st.top()-i)*m[i];
    	st.push(i);
    }
    for (int i=1;i<=n;i++) {
    	if (l[i]+r[i]-m[i]>mx) {
    		mx=l[i]+r[i]-m[i];
    		pos=i;
    	}
    }
    vector<int>v1,v2;
    long long cur=m[pos];
    for (int i=pos;i>=1;i--) {
    	v1.push_back(min(m[i],cur));
    	cur=min(cur,m[i]);
    }
    cur=m[pos];
    for (int i=pos;i<=n;i++) {
    	v2.push_back(min(m[i],cur));
    	cur=min(cur,m[i]);
    }
    for (int i=v1.size()-1;i>=1;i--) cout<<v1[i]<<' ';
    for (auto i:v2) cout<<i<<' ';
}