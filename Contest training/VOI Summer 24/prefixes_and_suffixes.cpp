#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,z[N+5];
string s;
long long base=311,mod=1e9+7,power[N+5],hs[N+5];
void prep() {
	s=' '+s;
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base+(int)s[i])%mod;
	}
}
long long get(long long l,long long r) {
	return (hs[r]-hs[l-1]*power[r-l+1]+mod*mod)%mod;
}
vector<pair<int,int>>res;
int cnt[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>s;
    n=s.size();
    int l=0,r=0;
    z[0]=0;
    z[1]=n;
    cnt[n]++;
    for (int i=1;i<n;i++) {
        z[i]=0;
        if (i<r) z[i]=min(r-i,z[i-l]);
        while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]>r) {
            l=i;
            r=i+z[i];
        }
        cnt[z[i]]++;
    }
    for (int i=n-1;i>=1;i--) cnt[i]+=cnt[i+1];
    prep();
    for (int i=1;i<=n;i++) {
    	if (get(1,i)!=get(n-i+1,n)) continue;
    	res.push_back({i,cnt[i]});
    }
    cout<<res.size()<<'\n';
    for (auto [x,y]:res) cout<<x<<' '<<y<<'\n';
}
