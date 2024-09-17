#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
long long base1=311,mod1=1e9+7;
long long power1[N+5],hs1[N+5];
long long base2=411,mod2=1e9+11;
long long power2[N+5],hs2[N+5];
void prep() {
	power1[0]=power2[0]=1;
	for (int i=1;i<=n;i++) {
		power1[i]=power1[i-1]*base1%mod1;
		hs1[i]=(hs1[i-1]*base1+(int)s[i])%mod1;
		power2[i]=power2[i-1]*base2%mod2;
		hs2[i]=(hs2[i-1]*base2+(int)s[i])%mod2;
	}
}
pair<long long,long long> get(long long l,long long r) {
	return {(hs1[r]-hs1[l-1]*power1[r-l+1]+mod1*mod1)%mod1,(hs2[r]-hs2[l-1]*power2[r-l+1]+mod2*mod2)%mod2};
}
vector<pair<pair<long long,long long>,int>>p;
int calc(int len) {
	p.clear();
	for (int i=1;i+len-1<=n;i++) 
		p.push_back({get(i,i+len-1),i});
	sort(p.begin(),p.end());
	for (int i=0;i<(int)p.size()-1;i++) {
		if (p[i].first==p[i+1].first) {
			return p[i].second;
		}
	}
	return -1;
}
int res=-1,pos;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    prep();
    int lo=1,hi=n;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	int t=calc(mid);
    	if (t!=-1) {
    		pos=t;
    		res=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    if (res==-1) cout<<-1;
    else cout<<s.substr(pos,res);
}