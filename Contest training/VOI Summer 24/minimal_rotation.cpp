#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=2e6;
int n;
string s;
long long base=311,mod=1e9+7,power[N+5],hs[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=n*2;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base+(int)s[i])%mod;
	}
}
long long get(long long l,long long r) {
	return (hs[r]-hs[l-1]*power[r-l+1]+mod*mod)%mod;
}
int res=1;
bool check(int l1,int l2,int len) {
	long long hs1=get(l1,l1+len-1),hs2=get(l2,l2+len-1);
	return (hs1!=hs2);
}
bool comp(int p1,int p2) {
	int lo=1,hi=n,ans=-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(p1,p2,mid)) {
			ans=mid;
			hi=mid-1;
		} else lo=mid+1;
	}	
	if (ans==-1) return false;
	int pos1=p1+ans-1,pos2=p2+ans-1;
	if (pos1>n) pos1-=n;
	if (pos2>n) pos2-=n;
	if (s[pos1]<s[pos2]) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s+=s;
    s=' '+s;
    prep();
    for (int i=2;i<=n;i++) 
    	if (comp(i,res)) res=i;
	for (int i=res;i<=n;i++) cout<<s[i];
	for (int i=1;i<res;i++) cout<<s[i];
}