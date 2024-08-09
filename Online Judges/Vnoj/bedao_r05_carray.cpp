#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>cprs;
int n;
int a[N+5],res;
int f[N+5],g[N+5];
int bit1[N+5],bit2[N+5];
void update1(int x,int val) {
	int idx=x;
	while (idx<=n) {
		bit1[idx]=max(bit1[idx],val);
		idx+=idx&(-idx);
	}
}
void update2(int x,int val) {
	int idx=x;
	while (idx>0) {
		bit2[idx]=max(bit2[idx],val);
		idx-=idx&(-idx);
	}
}
int get1(int x) {
	int idx=x,ans=0;
	while (idx>0) {
		ans=max(ans,bit1[idx]);
		idx-=idx&(-idx);
	}
	return ans;
}
int get2(int x) {
	int idx=x,ans=0;
	while (idx<=n) {
		ans=max(ans,bit2[idx]);
		idx+=idx&(-idx);
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
    for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	for (int i=n;i>=1;i--) {
		f[i]=get1(a[i]-1)+1;
		g[i]=get2(a[i]+1)+1;
		res=max(res,f[i]+g[i]-1);
		update1(a[i],f[i]);
		update2(a[i],g[i]);
	}
	cout<<res;
}