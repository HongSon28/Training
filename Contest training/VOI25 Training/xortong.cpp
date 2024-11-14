#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20);
int n;
int a[N+5];
int bit[N+5];
void update(int idx) {
	idx++;
	while (idx<=N+1) {
		bit[idx]++;
		idx+=(idx&(-idx));
	}
} 
int get(int idx) {
	idx++;
	int ans=0;
	while (idx>=1) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int getsum(int l,int r) {
	r=min(r,N);
	if (l>r) return 0;
	if (l==0) return get(r);
	return get(r)-get(l-1);
}
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for (int k=0;k<=20;k++) {
		memset(bit,0,sizeof(bit));
		update(0);
		int cnt=0;
		for (int i=1;i<=n;i++) {
			cnt+=getsum(a[i]%(1<<(k+1))+1,a[i]%(1<<(k+1))+(1<<k));
			cnt+=getsum(0,a[i]%(1<<(k+1))-(1<<k));
			cnt%=2;
			update(a[i]%(1<<(k+1)));
			//cout<<k<<' '<<i<<' '<<(a[i]%(1<<(k+1))-(1<<k)<0)<<' '<<cnt<<endl;
		}
		res+=cnt*(1<<k);
	}
	cout<<res;
}