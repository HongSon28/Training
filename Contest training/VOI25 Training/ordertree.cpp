#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
string s[N+5];
long long base=311,mod=1e9+7;
vector<vector<long long>>hs;
long long power[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=N;i++) power[i]=power[i-1]*base%mod;
	hs.resize(n+2);
	for (int i=1;i<=n;i++) {
		hs[i].resize(s[i].size()+2);
		for (int j=1;j<(int)s[i].size();j++) hs[i][j]=(hs[i][j-1]*base+(int)s[i][j])%mod;
	}
}
long long get(int id,int l,int r) {
	return (hs[id][r]-hs[id][l-1]*power[r-l+1]+mod*mod)%mod;
}
pair<int,int>p[N+5];
long long res;
vector<pair<int,int>>v;
bool check(int st,int cnt,int pre,int suf) {
	v.clear();
	for (int i=st;i<=n;i++) {
		int len=p[i].first,pos=p[i].second;
		v.push_back(make_pair(get(pos,1,pre),get(pos,len-suf+1,len)));
	}
	sort(v.begin(),v.end());
	int cur=1;
	for (int i=1;i<(int)v.size();i++) {
		if (v[i]==v[i-1]) cur++;
		else cur=1;
		if (cur>=cnt) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	p[i]=make_pair((int)s[i].size(),i);
    	s[i]=' '+s[i];
    }	
    sort(p+1,p+1+n);
    int cur=1,mx=p[n].first;
    prep();
    for (int pre=1;pre<=mx;pre++) {
    	while (cur<=n&&p[cur].first<pre) cur++;
    	if (n-cur+1<2) break;
    	for (int cnt=2;cnt<=n-cur+1;cnt++) {
    		int suf=0,lo=1,hi=mx;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (check(cur,cnt,pre,mid)) {
    				suf=mid;
    				lo=mid+1;
    			} else hi=mid-1;
    		}
    		//cout<<cur<<' '<<cnt<<' '<<pre<<' '<<suf<<endl;
    		res=max(res,1ll*cnt*pre*suf);
    	}
    }
    cout<<res;
}