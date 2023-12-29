#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int h[N+5],r[N+5],f[N+5];
stack<int>st;
int calc(int x) {
	if (f[x]!=-1) return f[x];
	if (!r[x]) return 0;
	return f[x]=calc(r[x])+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>h[i]; 
	for (int i=n;i>=1;i--) {
		while (!st.empty()&&h[i]>=h[st.top()]) st.pop();
		if (!st.empty()) r[i]=st.top();
		st.push(i);
		f[i]=-1;
	}
	while (q--) {
		int x;
		cin>>x;
		cout<<calc(x)<<'\n';
	}
}