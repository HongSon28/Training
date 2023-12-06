#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,res,cur;
int t[N+5];
vector<int>k[N+5];
bool check(int tm) {
	int cnt=0;
	for (int i=1;i<=n;i++) {
		for (auto j:k[i]) cnt+=(j<=tm);
	}
	return cnt>=m;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>t[i];
		int temp;
		cin>>temp;
		while (temp--) {
			int t;
			cin>>t;
			t-=cur;
			k[i].push_back(t);
		}
		cur+=t[i];
	}
	int lo=0,hi=1e9;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<cur+res;
}