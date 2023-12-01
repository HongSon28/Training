#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int mx,res,mod=2023;
struct trap{
	int a,b,c,d;
	bool operator < (const trap &other) const {
		if (a!=other.a) return a<other.a;
		if (b!=other.b) return b<other.b;
		if (c!=other.c) return c<other.c;
		return d<other.d;
 	}
} a[N+5];
vector<int>cprs1,cprs2;
pair<int,int>mer(pair<int,int>a,pair<int,int>b) {
	if (a.first>b.first) return a;
	if (a.first<b.first) return b;
	return {a.first,(a.second+b.second)%mod};
}
pair<int,int>st[N*4+5];
void update(int id,int l,int r,int pos,int val,int way) {
	if (l>pos||r<pos) return;
	if (l==r) {
		if (st[id].first<val) st[id]={val,way};
		else if (st[id].first==val) {
			st[id].second+=way;
			st[id].second%=mod;
		}
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val,way);
	update(id*2+1,mid+1,r,pos,val,way);
	st[id]=mer(st[id*2],st[id*2+1]);
}
pair<int,int>get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return mer(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
struct dat{
	int b,d,mx,way;
	bool operator < (const dat &other) const {
		return b>other.b;
	}
};
priority_queue<dat>pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
		cprs1.push_back(a[i].a);
		cprs1.push_back(a[i].b);
		cprs2.push_back(a[i].c);
		cprs2.push_back(a[i].d);
	}
	sort(cprs1.begin(),cprs1.end());
	sort(cprs2.begin(),cprs2.end());
	cprs1.resize(unique(cprs1.begin(),cprs1.end())-cprs1.begin());
	cprs2.resize(unique(cprs2.begin(),cprs2.end())-cprs2.begin());
	for (int i=1;i<=n;i++) {
		a[i].a=lower_bound(cprs1.begin(),cprs1.end(),a[i].a)-cprs1.begin()+1;
		a[i].b=lower_bound(cprs1.begin(),cprs1.end(),a[i].b)-cprs1.begin()+1;
		a[i].c=lower_bound(cprs2.begin(),cprs2.end(),a[i].c)-cprs2.begin()+1;
		a[i].d=lower_bound(cprs2.begin(),cprs2.end(),a[i].d)-cprs2.begin()+1;
	}
	sort(a+1,a+1+n);
	//for (int i=1;i<=n;i++) cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].d<<endl;
	//cout<<endl;
	int l=1;
	for (int i=1;i<=n;i++) {
		while (!pq.empty()&&pq.top().b<a[i].a) {
			update(1,0,N,pq.top().d,pq.top().mx,pq.top().way);
			pq.pop();
		}
		pair<int,int>temp=get(1,0,N,0,a[i].c-1);
		int way=temp.second;
        if (temp.first==0) way=1;
        if (temp.first+1>mx) {
            mx=temp.first+1;
            res=way;
        } else if(temp.first+1==mx){
            res+=way;
            res%=mod;
        }
        pq.push({a[i].b,a[i].d,temp.first+1,way});
        //cout<<"get "<<a[i].c-1<<' '<<temp.first<<' '<<temp.second<<endl;
        //cout<<mx<<' '<<res<<endl;
	}
	cout<<mx<<' '<<res;
}