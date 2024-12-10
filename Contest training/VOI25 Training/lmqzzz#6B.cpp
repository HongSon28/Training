#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N+5];
int res;
bool used[N+5];
multiset<int>ms;
bool add(int id) {
	if (used[a[id]]) return false;
	if (ms.empty()) {
		used[a[id]]=true;
		ms.insert(a[id]);
		return true;
	}
	int mn=(*ms.begin()),mx=(*ms.rbegin());
	mx=max(mx,a[id]),mn=min(mn,a[id]);
	if (mx-mn+1<=k) {
		used[a[id]]=true;
		ms.insert(a[id]);
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];	
		a[i+n]=a[i];
	}
	int r=0;
	for (int l=1;l<=n;l++) {
		while (add(r+1)) r++;
		res=max(res,r-l+1);
		used[a[l]]=false;
		ms.erase(ms.lower_bound(a[l]));
	}
	cout<<k-res;
}