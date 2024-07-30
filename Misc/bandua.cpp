#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int a[N+5],cnt[N+5];
int res;
bool used[N+5];
vector<int>b;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=k;i++) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+1+k,greater<int>());
	for (int i=1;i<=k;i++) {
		if (a[i]!=a[i-1]&&b.size()<n) {
			b.push_back(a[i]);
			res+=a[i];
			used[a[i]]=true;
		} 
	}
	if (b.size()==n) {
		cout<<res;
		return 0;
	}
	int cur=n-b.size();
	for (int i=b.size()-1;i>=0;i--) {
		if (!used[b[i]]) continue;
		res-=b[i];
		if (cur<=cnt[b[i]])	break;
		else cur-=cnt[b[i]];
	}
	cout<<res;
}