#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int t,n,k;
int a[N+5];
int c1[N+5],c2[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	for (int i=1;i<=2*k;i++) c1[i]=c2[i]=0;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=1;i<=n/2;i++) {
    		c1[a[i]+a[n-i+1]]++;
    		int l=min(a[i]+1,a[n-i+1]+1);
    		int r=max(a[i]+k,a[n-i+1]+k);
    		c2[l]++;
    		c2[r+1]--;
    	}
    	for (int i=1;i<=2*k;i++) c2[i]+=c2[i-1];
    	int res=1e9;
    	for (int s=2;s<=2*k;s++) {
    		int cnt1=c2[s]-c1[s];
    		int cnt2=n/2-cnt1-c1[s];
    		res=min(res,cnt1+cnt2*2);
    		//cout<<s<<' '<<c1[s]<<' '<<cnt1<<' '<<cnt2<<' '<<cnt1+cnt2*2<<endl;
    	}
    	cout<<res<<'\n';
    }
}