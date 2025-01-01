#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
int a[N+5];
map<long long,long long>cnt;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	for (int i=1;i<=n;i++) {
		if (s[i]>='a'&&s[i]<='z') a[i]=(int)s[i]-'a';
		else a[i]=(int)s[i]-'0'+26;
		//cout<<a[i]<<endl;
	}
	long long mask=0;
	cnt[mask]++;
	for (int i=1;i<=n;i++) {
		mask^=(1ll<<a[i]);
		res+=cnt[mask];
		for (int j=0;j<=35;j++) {
			long long temp=(mask^(1ll<<j));
			res+=cnt[temp];
		}
		cnt[mask]++;
	}
	cout<<res;
}