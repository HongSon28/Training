#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
using pll=pair<long long,long long>;
int n;
int a[N+5];
int l[N+5],r[N+5];
int st[N+5],top;
long long mod1=1e9+7,mod2=1e9+11;
long long binpow(int x,long long mod) {
	long long ans=1;
	long long cur=2;
	while (x) {
		if (x&1) ans=(ans*cur)%mod;
		cur=(cur*cur)%mod;
		x>>=1;
	}
	return ans;
}
vector<int>pos[N*LG+5];
vector<pll>cprs;
pll sum[N+5];
int lg;
long long res;
long long cnt(pll cur,int l,int r) {
	int t=lower_bound(cprs.begin(),cprs.end(),cur)-cprs.begin();
	if (cprs[t]!=cur) return 0;
	t++;
	int lo=0,hi=pos[t].size()-1;
	int resl=-1,resr=-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (pos[t][mid]>=l) {
			resl=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	lo=0,hi=pos[t].size()-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (pos[t][mid]<=r) {
			resr=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	if (resl==-1||resr==-1) return 0;
	return resr-resl+1;
}
void solve(int i) {
	pll p={binpow(a[i],mod1),binpow(a[i],mod2)};
	if (i-l[i]<=r[i]-i) {
		for (int j=l[i];j<=i;j++) {
			pll cur=p;
			for (int t=0;t<=__lg(r[i]-l[i]+1);t++) {
				pll temp={cur.first+sum[j-1].first,
						  cur.second+sum[j-1].second};
				if (temp.first>=mod1) temp.first-=mod1;
				if (temp.second>=mod2) temp.second-=mod2;
				res+=cnt(temp,i,r[i]);
				cur.first*=2;
				cur.second*=2;
				if (cur.first>=mod1) cur.first-=mod1;
				if (cur.second>=mod2) cur.second-=mod2;
			}
		}
	} else {
		for (int j=i;j<=r[i];j++) {
			pll cur=p;
			for (int t=0;t<=__lg(r[i]-l[i]+1);t++) {
				pll temp={sum[j].first-cur.first,
						  sum[j].second-cur.second};
				if (temp.first<0) temp.first+=mod1;
				if (temp.second<0) temp.second+=mod2;
				res+=cnt(temp,l[i]-1,i-1);
				cur.first*=2;
				cur.second*=2;
				if (cur.first>=mod1) cur.first-=mod1;
				if (cur.second>=mod2) cur.second-=mod2;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    lg=__lg(n)+1;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	while (top!=0&&a[st[top]]<=a[i]) top--;
    	l[i]=st[top]+1;
    	st[++top]=i;
    }
    top=0;
    for (int i=n;i>=1;i--) {
    	while (top!=0&&a[st[top]]<a[i]) top--;
    	if (top!=0) r[i]=st[top]-1;
    	else r[i]=n;
    	st[++top]=i;
    }
    for (int i=1;i<=n;i++) {
    	sum[i].first=sum[i-1].first+binpow(a[i],mod1);
    	sum[i].second=sum[i-1].second+binpow(a[i],mod2);
    	if (sum[i].first>=mod1) sum[i].first-=mod1;
    	if (sum[i].second>=mod2) sum[i].second-=mod2;
    	cprs.push_back(sum[i]);
    }
    cprs.push_back({0,0});
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=0;i<=n;i++) {
    	int t=lower_bound(cprs.begin(),cprs.end(),sum[i])-cprs.begin()+1;
		pos[t].push_back(i);
	}
	for (int i=1;i<=n;i++) solve(i);
	cout<<res;
}