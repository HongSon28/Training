#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,k,res;
string s;
long long base=31,mod=1e9+7;
long long power[N+5],hs[N+5];
void create_hash() {
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base%mod+s[i]-'a')%mod;
	}
}
long long get(int l,int r) {
	return (hs[r]-hs[l-1]*power[r-l+1]%mod+mod)%mod;
}
bool check(int len) {
	map<long long,int>mp;
	for (int i=1;i+len-1<=n;i++) {
		long long temp=get(i,i+len-1);
		mp[temp]++;
		if (mp[temp]>=k) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>s;
    s=' '+s;
    create_hash();
    int lo=0,hi=n;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		lo=mid+1;
    	} else hi=mid-1;
    }
    cout<<res;
}