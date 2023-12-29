#include<bits/stdc++.h>
using namespace std;
string s;
set<long long>st;
long long res;
bool check(long long x) {
	if (x<=1) return false;
	for (long long i=2;i*i<=x;i++) {
		if (x%i==0) return false;
	}
	return true;
}
int main() {
	freopen("TONGNT.INP","r",stdin);
	freopen("TONGNT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	long long cur=0;
	for (int i=0;i<(int)s.size();i++) {
		if (s[i]>='0'&&s[i]<='9'){
			cur*=10;
			cur+=s[i]-'0';
		} else {
			if (cur!=0) st.insert(cur);
			cur=0;
		}
	} 
	if (cur!=0) st.insert(cur);
	for (auto i:st) {
		if (check(i)) res+=i;
	}
	cout<<res;
}