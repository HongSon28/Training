#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=16;
int n;
int a[N+5],l[N+5],r[N+5],rmq[N+5][LG+5];
stack<int>st;
vector<int>v1[N+5],v2[N+5];
long long res;
int get(int l,int r) {
	int k=__lg(r-l+1);
	return max(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		rmq[i][0]=a[i];
	}
	for (int j=1;j<=__lg(n);j++) {
		for (int i=1;i+(1<<j)-1<=n;i++) rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	}
	for (int i=1;i<=n;i++) {
		while (!st.empty()&&a[st.top()]<a[i]) st.pop();
		if (st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n;i>=1;i--) {
		while (!st.empty()&&a[st.top()]<a[i]) st.pop();
		if (st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	for (int i=1;i<=n;i++) {
		v1[l[i]].push_back(i);
		v2[r[i]].push_back(i);
		res+=(i-l[i]-1)+(r[i]-i-1);
		//cout<<l[i]<<' '<<r[i]<<' '<<res<<endl;
	}
	for (int i=1;i<=n;i++) {
		long long cur=res-(i-l[i]-1)-(r[i]-i-1);
		//cout<<res<<' '<<cur<<endl;
		for (auto j:v1[i]) {
			cur-=j-i-1;
			int ans=0,lo=1,hi=i-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (get(mid,i-1)>a[j]) {
					ans=mid;
					lo=mid+1;
				} else hi=mid-1;
			}
			cur+=j-ans-1;
			//cout<<j<<' '<<l[j]<<' '<<ans<<' '<<cur<<endl;
		}
		for (auto j:v2[i]) {
			cur-=i-j-1;
			int ans=n+1,lo=i+1,hi=n;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (get(i+1,mid)>a[j]) {
					ans=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			cur+=ans-j-1;
		}
		cout<<cur+n<<'\n';
	}
} 