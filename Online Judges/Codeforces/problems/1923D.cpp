#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int t,n;
long long a[N+5],sum[N+5],mx[N+5][20];
long long getmax(int l,int r) {
	int lg=__lg(r-l+1);
	return max(mx[l][lg],mx[r-(1<<lg)+1][lg]);
}
bool check(int l,int r) {
	if (l==r) return true;
	long long cur=sum[r]-sum[l-1];
	if (cur%(r-l+1)!=0) return true;
	return getmax(l,r)>cur/(r-l+1);
}
int binleft(int st,long long val) {
	int res=n+1,hi=st,lo=1;
	if (st>0&&a[st]>val) return 1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (sum[st]-sum[mid-1]>val&&check(mid,st)) {
			res=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	//cout<<"LEFT "<<st<<' '<<val<<' '<<res<<endl;
	if (res!=n+1) return st-res+1;
	return res;
}
int binright(int st,long long val) {
	int res=n+1,hi=n,lo=st;
	if (st<n&&a[st]>val) return 1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (sum[mid]-sum[st-1]>val&&check(st,mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	//cout<<"RIGHT "<<st<<' '<<val<<' '<<res<<endl;
	if (res!=n+1) return res-st+1;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		sum[i]=sum[i-1]+a[i];
    		mx[i][0]=a[i];
    	}
    	for (int i=1;(1<<i)<=n;i++) {
    		for (int j=1;j+(1<<i)-1<=n;j++) {
    			mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
    		}
    	}
    	for (int i=1;i<=n;i++) {
    		int res=min(binleft(i-1,a[i]),binright(i+1,a[i]));
    		if (res==n+1) cout<<-1<<' ';
    		else cout<<res<<' ';
    	}
    	cout<<'\n';
    }
}