#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
struct dat{
	long long x;
	int l,r,type;
	bool operator < (const dat &other) const {
		if (x!=other.x) return x<other.x;
		return type<other.type;
	}
};
vector<dat>v;
vector<int>comp;
struct node {
	long long odd,even;
	int lazy;
	int mi;
	long long slmi;
} st[N*4+5];
void down(int id) {
	if (st[id].lazy==0) return;
	int t=st[id].lazy;
	st[id].lazy=0;
	st[id*2].lazy+=t,st[id*2+1].lazy+=t;
	st[id*2].mi+=t,st[id*2+1].mi+=t;
	if (abs(t)%2==1) {
		swap(st[id*2].odd,st[id*2].even);
		swap(st[id*2+1].odd,st[id*2+1].even);
	}
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id].odd=st[id].mi=st[id].lazy=0;
		st[id].even=st[id].slmi=comp[l+1]-comp[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].odd=st[id].mi=st[id].lazy=0;
	st[id].even=st[id].slmi=st[id*2].even+st[id*2+1].even;
}
void update(int id,int l,int r,int u,int v,int val) {
	if (l>v||r<u||u>v) return;
	if (u<=l&&r<=v) {
		st[id].lazy+=val;
		st[id].mi+=val;
		swap(st[id].odd,st[id].even);
		return;
	}
	int mid=(l+r)/2;
	down(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id].mi=min(st[id*2].mi,st[id*2+1].mi);
	if (st[id].mi==st[id*2].mi) st[id].slmi=st[id*2].slmi;
	if (st[id].mi==st[id*2+1].mi) st[id].slmi=st[id*2+1].slmi;
	if (st[id*2].mi==st[id*2+1].mi) st[id].slmi=st[id*2].slmi+st[id*2+1].slmi;
	st[id].odd=st[id*2].odd+st[id*2+1].odd;
	st[id].even=st[id*2].even+st[id*2+1].even;
}
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	int x1,y1,x2,y2;
    	cin>>x1>>y1>>x2>>y2;
    	//if (x1==x2||y1==y2) continue;
    	if (x1>x2) swap(x1,x2);
    	if (y1>y2) swap(y1,y2);
    	v.push_back({x1,y1,y2,1});
    	v.push_back({x2,y1,y2,-1});
    	comp.push_back(y1);
    	comp.push_back(y2);
    }
    sort(comp.begin(),comp.end());
    comp.resize(unique(comp.begin(),comp.end())-comp.begin());
    for (int i=0;i<(int)v.size();i++) {
    	v[i].l=lower_bound(comp.begin(),comp.end(),v[i].l)-comp.begin();
    	v[i].r=lower_bound(comp.begin(),comp.end(),v[i].r)-comp.begin();
    }
    m=comp.size()-1;
    if (m==0) {
    	cout<<0;
    	return 0;
    }
    sort(v.begin(),v.end());
    build(1,0,m-1);
    for (int i=0;i<(int)v.size();i++) {
    	if (i!=0) res+=(st[1].even-(!st[1].mi)*st[1].slmi)*(v[i].x-v[i-1].x);
    	//cout<<v[i].x<<' '<<st[1].mi<<' '<<st[1].slmi<<' '<<st[1].even<<' '<<st[1].even-(!st[1].mi)*st[1].slmi<<' '<<res<<endl;
    	update(1,0,m-1,v[i].l,v[i].r-1,v[i].type);
    }
    cout<<res;
}
