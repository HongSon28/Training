#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],bit[N+5];
vector<int>cprs;
void update (int u) {
	int idx=u;
	while (idx<=n) {
		bit[idx]++;
		idx+=(idx&(-idx));
	}
}
int get(int u) {
	int ans=0;
	int idx=u;
	while (idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];	
		cprs.push_back(a[i]);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) {
		a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
		update(a[i]);
	}
	for (int i=1;i<=n;i++) cout<<get(a[i]-1)<<' ';
}