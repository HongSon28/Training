#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,res;
long long d,t;
long long a[N+5];
void Try(long long dif) {
	map<long long,int>mp;
	for (int i=1;i<=n;i++) mp[a[i]%dif]++;
	for (auto i=mp.begin();i!=mp.end();i++) {
		if (i->second>res) {
			res=i->second;
			d=dif;
			t=i->first;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n>50) {
    	for (int k=2;k<=101;k++) Try(k);
    } else {
    	for (int i=1;i<=min(n,5);i++) {
	    	for (int j=i+1;j<=min(n,i+5);j++) {
	    		long long dif=abs(a[i]-a[j]);
	    		for (long long div=2;div*div<=dif;div++) {
	    			if (dif%div!=0) continue;
	    			Try(div);
	    			Try(dif/div);
	    		}
	    		if (dif>1) Try(dif);
	    	}
		}
    }
    cout<<res<<' '<<d<<'\n';
    for (int i=1;i<=n;i++) 
    	if (a[i]%d==t) cout<<i<<' ';
}