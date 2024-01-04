#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long t,n,m;
int a[N+5],b[N+5];
map<int,int>mp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		mp.clear();
		long long res1=0,res2=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			mp[a[i]]++;
		}
		cin>>m;
		for (int i=1;i<=m;i++) {
			cin>>b[i];
			res2+=mp[b[i]];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		int j=0;
		for (int i=1;i<=n;i++) {
			while (j+1<=m&&b[j+1]<a[i]) j++;
			res1+=j;
		}
		long long g=__gcd(res1,n*m);
		cout<<res1/g<<'/'<<n*m/g<<'\n';
		g=__gcd(res2,n*m);
		cout<<res2/g<<'/'<<n*m/g<<'\n';
	}
}