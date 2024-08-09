#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
int l[N+5],r[N+5];
int main() {
	freopen("FNCS.inp","r",stdin);
    freopen("FNCS.ans","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
	cin>>q;
	while (q--) {
		int type,x,y;
		cin>>type>>x>>y;
		if (type==1) a[x]=y;
		else {
			long long res=0;
			for (int i=x;i<=y;i++) {
				for (int j=l[i];j<=r[i];j++) res+=a[j];
			}
			cout<<res<<'\n';
		}
	}
}