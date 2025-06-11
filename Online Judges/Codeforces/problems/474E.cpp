#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long d;
long long h[N+5];
vector<long long>cprs;
int dp[N+5],trace[N+5];
int pos;
pair<int,int>st[N*4+5];
void update(int id,int l,int r,int pos,int pid,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		if (st[id].first<val) st[id]={val,pid};
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,pid,val);
	update(id*2+1,mid+1,r,pos,pid,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
pair<int,int>get(int id,int l,int r,int u,int v) {
	if (l>v||r<u||u>v) return {0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>d;
    cprs.push_back(0);
    for (int i=1;i<=n;i++) {
    	cin>>h[i];
    	cprs.push_back(h[i]);
    }	
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    int m=cprs.size()-1;
    dp[1]=1;
    pos=1;
    memset(trace,-1,sizeof(trace));
    update(1,1,m,lower_bound(cprs.begin(),cprs.end(),h[1])-cprs.begin(),1,1);
    for (int i=2;i<=n;i++) {
    	int l=0,r=m+1,lo=1,hi=m;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (h[i]-cprs[mid]>=d) {
    			l=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	lo=1,hi=m;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (cprs[mid]-h[i]>=d) {
    			r=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	pair<int,int>g1=get(1,1,m,1,l);
    	pair<int,int>g2=get(1,1,m,r,m);
    	if (g1.first>g2.first) {
    		dp[i]=g1.first+1;
    		trace[i]=g1.second;
    	} else if (g2.first!=0){
    		dp[i]=g2.first+1;
    		trace[i]=g2.second;
    	} else {
    		dp[i]=1;
    	}
    	update(1,1,m,lower_bound(cprs.begin(),cprs.end(),h[i])-cprs.begin(),i,dp[i]);
    	if (dp[i]>dp[pos]) pos=i;
    	//cout<<i<<' '<<dp[i]<<' '<<trace[i]<<' '<<lower_bound(cprs.begin(),cprs.end(),h[i])-cprs.begin()<<' '<<l<<' '<<r<<endl;
    }
    cout<<dp[pos]<<'\n';
    vector<int>vc;
    while (pos!=-1) {
    	vc.push_back(pos);
    	pos=trace[pos];
    }
    reverse(vc.begin(),vc.end());
    for (auto x:vc) cout<<x<<' ';
}