#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long l,r;
long long a[N+5],sum[N+5];
vector<long long>cprs;
map<long long,long long>mp;
long long res;
long long st[N*4+5];
long long get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]++;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	st[id]=st[id*2]+st[id*2+1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    	cprs.push_back(sum[i]);
    	cprs.push_back(sum[i]-l);
    	cprs.push_back(sum[i]-r);
    }	
    cprs.push_back(0);
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) {
    	mp[sum[i]]=lower_bound(cprs.begin(),cprs.end(),sum[i])-cprs.begin()+1;
    	mp[sum[i]-l]=lower_bound(cprs.begin(),cprs.end(),sum[i]-l)-cprs.begin()+1;
    	mp[sum[i]-r]=lower_bound(cprs.begin(),cprs.end(),sum[i]-r)-cprs.begin()+1;
    }
    mp[0]=lower_bound(cprs.begin(),cprs.end(),0)-cprs.begin()+1;
    update(1,1,N,mp[0]);
    for (int i=1;i<=n;i++) {
    	res+=get(1,1,N,mp[sum[i]-r],mp[sum[i]-l]);
    	//cout<<mp[sum[i]-r]<<' '<<mp[sum[i]-l]<<' '<<get(1,1,N,mp[sum[i]-r],mp[sum[i]-l])<<endl;
    	update(1,1,N,mp[sum[i]]);
    	//cout<<mp[sum[i]]<<endl;
    }
    cout<<res;
}