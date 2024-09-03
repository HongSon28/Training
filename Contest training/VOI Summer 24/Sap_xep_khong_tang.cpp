#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
pair<int,int>p[N+5];
int dp[N+5];
int st[N*4+5];
long long res;
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u||u>v) return -1;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(st,-1,sizeof(st));
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>a[i];
    	p[i]={a[i],i};
    }
    sort(p+1,p+1+n,greater<pair<int,int>>());
    queue<pair<int,int>>q;
    for (int i=1;i<=n;i++) {
    	int pos=p[i].second;
    	dp[pos]=max(get(1,1,n,1,pos-1),get(1,1,n,pos+1,n)+1);
    	q.push({pos,dp[pos]});
    	//cout<<pos<<endl;
    	if (p[i].first!=p[i+1].first) {
    		while (!q.empty()) {
	    		pair<int,int>temp=q.front();
	    		q.pop();
	    		update(1,1,n,temp.first,temp.second);
	    		//cout<<pos<<' '<<dp[pos]<<endl;
    		}
    	} 
    	res+=dp[pos];
    }
    cout<<res;
}