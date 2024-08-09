#include<bits/stdc++.h>
using namespace std;
int n,a,res;
vector<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a;
		while (!st.empty()&&st.back()==a) {
			st.pop_back();
			a++;
		}
		st.push_back(a);
		res=max(res,a);
	}
	for (int i=0;i<(int)st.size()-1;i++) {
		if (st[i]==st[i+1]) {
			res=max(res,st[i]+1);
		}
	}
	cout<<res;
}