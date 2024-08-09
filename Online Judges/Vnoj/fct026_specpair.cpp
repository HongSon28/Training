#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n;
int a[N+5],c[N+5];
long long res;
vector<int>v;
bool check(int x) {
	string s=to_string(x);
	for (int i=1;i<(int)s.size();i++) if (s[i]!=s[i-1]) return false;
	return true;
}
void prep() {
	for (int i=1;i<=N;i++) {
		if (check(i)) v.push_back(i);
	}
}
int main() {
	prep();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	for (auto s:v) {
    		if (s>a[i]) res+=c[s-a[i]];
    	}
    	c[a[i]]++;
    }
    cout<<res;
}