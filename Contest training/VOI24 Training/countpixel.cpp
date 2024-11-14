#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
struct Segment{
	long long x,y1,y2,val;
	bool operator < (const Segment &other) const {
		if (x!=other.x) return x<other.x;
		return val>other.val;
	}
};
int n,sz;
vector<Segment>seg;
vector<long long>cprs;
long long res;
struct node{
	long long even,odd,lazy;
};
node st[N*4+5];
void down(int id) {
	int temp=st[id].lazy;
	st[id].lazy=0;
	if (temp==0) return;
	st[id*2].lazy^=1;
	st[id*2+1].lazy^=1;
	swap(st[id*2].odd,st[id*2].even);
	swap(st[id*2+1].odd,st[id*2+1].even);
}
void build(int id,int l,int r) {
	if (l==r) {
		if (l<sz) st[id].even=cprs[l]-cprs[l-1];
		else st[id].even=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].even=st[id*2].even+st[id*2+1].even;
}
void update(int id,int l,int r,int u,int v) {
    if (u>r||l>v) return;
	if (u<=l&&r<=v) {
		swap(st[id].even,st[id].odd);
		st[id].lazy^=1;
		return;
	}
	down(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id].even=st[id*2].even+st[id*2+1].even;
	st[id].odd=st[id*2].odd+st[id*2+1].odd;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		long long x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		x2--;
		y2--;
		seg.push_back({x1,y1,y2,1});
		seg.push_back({x2+1,y1,y2,-1});
		cprs.push_back(y1);
		cprs.push_back(y2);
		cprs.push_back(y2+1);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	sz=cprs.size();
	for (int i=0;i<(int)seg.size();i++) {
		seg[i].y1=lower_bound(cprs.begin(),cprs.end(),seg[i].y1)-cprs.begin()+1;
		seg[i].y2=lower_bound(cprs.begin(),cprs.end(),seg[i].y2)-cprs.begin()+1;
	}
	build(1,1,sz);
	sort(seg.begin(),seg.end());
	for (int i=0;i<(int)seg.size();i++) {
		if (i>0) res+=st[1].odd*(seg[i].x-seg[i-1].x);
		//cout<<seg[i].x<<' '<<seg[i].y1<<' '<<seg[i].y2<<' '<<seg[i].val<<endl;
		update(1,1,sz,seg[i].y1,seg[i].y2);
	} 
	cout<<res;
}