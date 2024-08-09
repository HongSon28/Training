#include<bits/stdc++.h>
using namespace std;
const int N=2e5,M=1e6;
int t,n,m,k;
int a[N+5],b[N+5];
bool ca[M+5],cb[M+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		int cnt1=0,cnt2=0,cnt3=0;
		cin>>n>>m>>k;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			ca[a[i]]=true;
		}
		for (int i=1;i<=m;i++) {
			cin>>b[i];
			cb[b[i]]=true;
		}
		for (int i=1;i<=k;i++) {
			if (ca[i]&&cb[i]) cnt3++;
			else if (ca[i]&&!cb[i]) cnt1++;
			else if (!ca[i]&&cb[i]) cnt2++;
		}
		//cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<' '<<k<<' ';
		if (cnt1+cnt2+cnt3!=k) cout<<"NO"<<'\n';
		else if (2*cnt1>k||2*cnt2>k) cout<<"NO"<<'\n';
		else cout<<"YES"<<'\n';
		for (int i=1;i<=n;i++) ca[a[i]]=false;
		for (int i=1;i<=m;i++) cb[b[i]]=false;
	}
}