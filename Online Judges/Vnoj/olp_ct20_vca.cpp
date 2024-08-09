#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k,res=1e9;
string s;
int cv[N+5],ca[N+5],cc[N+5];
bool check(int l,int r) {
	return (cv[r]-cv[l-1]>=k&&ca[r]-ca[l-1]>=k&&cc[r]-cc[l-1]>=k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k>>s;
	n=s.size();
	s=' '+s;
	for (int i=1;i<=n;i++) {
		cv[i]=cv[i-1],cc[i]=cc[i-1],ca[i]=ca[i-1];
		if (s[i]=='V') cv[i]++;
		else if (s[i]=='C') cc[i]++;
		else ca[i]++;
	}
	for (int i=1;i<=n;i++) {
		int lo=i,hi=n,ans=-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (check(i,mid)) {
				ans=mid;
				hi=mid-1;
			} else lo=mid+1;
		}
		if (ans!=-1) {
			ans=ans-i+1;
			ans-=k*3;
			res=min(res,ans);
		}
	}
	if (res==1e9) cout<<-1;
	else cout<<res;
} 