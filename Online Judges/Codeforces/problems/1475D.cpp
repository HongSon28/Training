#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long m;
vector<long long>v1,v2;
long long s1[N+5],s2[N+5];
int a[N+5],inf=1e9;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		v1.clear(),v2.clear();
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) {
			int t;
			cin>>t;
			if (t==1) v1.push_back(a[i]);
			else v2.push_back(a[i]);
		}
		sort(v1.rbegin(),v1.rend());
		sort(v2.rbegin(),v2.rend());
		for (int i=1;i<=(int)v1.size();i++) s1[i]=s1[i-1]+v1[i-1];
		for (int i=1;i<=(int)v2.size();i++) s2[i]=s2[i-1]+v2[i-1];
		int res=inf;
		for (int i=0;i<=(int)v1.size();i++) {
			int lo=0,hi=(int)v2.size(),ans=-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (s1[i]+s2[mid]>=m) {
					ans=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			//cout<<s1[i]<<' '<<ans<<endl;
			if (ans!=-1) res=min(res,i+ans*2);
		}
		if (res==inf) cout<<-1<<'\n';
		else cout<<res<<'\n';
	}
}