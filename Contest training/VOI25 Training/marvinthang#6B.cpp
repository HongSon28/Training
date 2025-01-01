#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n,q;
long long a[N+5],b[N+5];
int x[N+5];
long long v[N+5];
vector<long long>cprs;
long long sum;
struct SegmentTree{
	long long st[N*4+5],val[N*4+5];
	void update(int id,int l,int r,int pos,int v) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]+=v;
			val[id]+=cprs[l]*v;
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos,v);
		update(id*2+1,mid+1,r,pos,v);
		st[id]=st[id*2]+st[id*2+1];
		val[id]=val[id*2]+val[id*2+1];
	}
	int get_cnt(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return get_cnt(id*2,l,mid,u,v)+get_cnt(id*2+1,mid+1,r,u,v);
	}
	long long get_sum(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return 0;
		if (u<=l&&r<=v) return val[id];
		int mid=(l+r)/2;
		return get_sum(id*2,l,mid,u,v)+get_sum(id*2+1,mid+1,r,u,v);
	}
} tree;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i];
		if (a[i]>0) cprs.push_back(a[i]);
	}
	for (int i=1;i<=q;i++) {
		cin>>x[i]>>v[i];
		b[x[i]]=v[i];
		if (b[x[i]]>0) cprs.push_back(b[x[i]]);
	}
	cprs.push_back(0);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	int m=cprs.size()-1;
	for (int i=1;i<=n;i++) {
		if (a[i]<=0) sum-=a[i];
		else {
			int t=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin();
			tree.update(1,1,m,t,1);
		}
	}
	for (int i=1;i<=q;i++) {
		if (a[x[i]]<=0) sum-=abs(a[x[i]]);
		else {
			int t=lower_bound(cprs.begin(),cprs.end(),a[x[i]])-cprs.begin();
			tree.update(1,1,m,t,-1);
		}
		a[x[i]]=v[i];
		if (a[x[i]]<=0) sum+=abs(a[x[i]]);
		else {
			int t=lower_bound(cprs.begin(),cprs.end(),a[x[i]])-cprs.begin();
			tree.update(1,1,m,t,1);
		}
		int pos=0,lo=1,hi=m;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (tree.get_sum(1,1,m,1,mid)<=sum) {
				pos=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		//cout<<sum<<' '<<pos<<endl;
		long long temp=sum-tree.get_sum(1,1,m,1,pos);
		int res=tree.get_cnt(1,1,m,1,pos);
		if (pos<m) res+=temp/cprs[pos+1];
		cout<<res+1<<'\n';
	}
}