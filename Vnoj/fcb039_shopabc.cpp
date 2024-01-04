#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,res;
string s;
int a[N+5],sum[N+5],mn[N+5];
void calc(char x) {
	for (int i=1;i<=n;i++) {
		if (s[i]==x) a[i]=1;
		else a[i]=-1;
		sum[i]=sum[i-1]+a[i];
		mn[i]=min(mn[i-1],sum[i]);
	}
	for (int i=1;i<=n;i++) {
		int lo=1,hi=i;
		int ans=i+1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (sum[i]-mn[mid-1]>0) {
				ans=mid;
				hi=mid-1;
			} else lo=mid+1;
		}
		res=max(res,i-ans+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	calc('a');
	calc('b');
	calc('c');
	cout<<res;
}