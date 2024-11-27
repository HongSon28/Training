#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long k;
int a[N+5];
long long f[N+5];
int bit[N+5];
void update(int idx,int val) {
	while (idx<=n) {
		bit[idx]+=val;
		idx+=(idx&(-idx));
	}
}
int get(int idx) {
	int ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main() {
	freopen("LEXORDER.INP","r",stdin);
	freopen("LEXORDER.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--) {
    	f[i]=get(a[i]-1);
    	update(a[i],1);
    }	
    int cur=1;
    for (int i=n;i>=1;i--) {
    	f[i]+=k;
    	k=f[i]/cur;
    	f[i]%=cur;
    	cur++;
    }
    if (k!=0) {
    	cout<<-1;
    	return 0;
    }
    for (int i=1;i<=n;i++) {
    	int lo=1,hi=n,ans=-1;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (get(mid)>=f[i]+1) {
    			ans=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	if (ans==-1) {
    		cout<<-1;
    		return 0;
    	}
    	a[i]=ans;
    	update(a[i],-1);
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
}