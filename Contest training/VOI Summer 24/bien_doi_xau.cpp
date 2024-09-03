#include<bits/stdc++.h>
using namespace std;
const int N=150000;
int n,m;
string s;
struct query{
	int type,t,id;
	char c1,c2;
	bool operator < (const query &other) {
		if (t!=other.t) return t<other.t;
		return type<other.type;
	}
};
vector<query>v;
struct node{
	int a[26];
} st[N*4+5];
node merge(node x,node y) {
	node res;
	for (int i=0;i<26;i++) res.a[i]=y.a[x.a[i]];
	return res;
}
void build(int id,int l,int r) {
	for (int i=0;i<26;i++) st[id].a[i]=i;
	if (l==r) return;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
void update(int id,int l,int r,int pos,int c1,int c2) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].a[c1]=c2;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,c1,c2);
	update(id*2+1,mid+1,r,pos,c1,c2);
	st[id]=merge(st[id*2],st[id*2+1]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    cin>>m;
    for (int i=1;i<=m;i++) {
    	int l,r;
    	char c1,c2;
    	cin>>l>>r>>c1>>c2;
    	v.push_back({1,l,i,c1,c2});
    	v.push_back({0,r+1,i,c1,c1});
    }
    sort(v.begin(),v.end());
    int cur=0;
    //for (auto [type,t,id,c1,c2]:v) cout<<type<<' '<<t<<' '<<id<<' '<<c1<<' '<<c2<<endl;
    build(1,1,m);
    for (int i=0;i<n;i++) {
    	while (cur<v.size()&&v[cur].t==i) {
    		//cout<<v[cur].t<<' '<<v[cur].id<<' '<<v[cur].c1-'a'<<' '<<v[cur].c2-'a'<<endl;
    		update(1,1,m,v[cur].id,v[cur].c1-'a',v[cur].c2-'a');
    		cur++;
    	}
    	cout<<(char)('a'+st[1].a[s[i]-'a']);
    }
}