#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int used[10];
string t;
set<string>st;
void rec(int k) {
	if (k==n) {
		st.insert(t);
		return;
	}
	for (int i=0;i<n;i++) {
		if (!used[i]) {
			used[i]=true;
			t[k]=s[i];
			rec(k+1);
			used[i]=false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	n=s.size();
	t.resize(n);
	rec(0);
	cout<<st.size()<<'\n';
	for (auto i:st) cout<<i<<'\n';
}