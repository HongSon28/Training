#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,c,d;
vector<pair<int,int>>vc,vd;
int inf=1e9;
struct Fenwick{
	int bit[N+5];
	void reset() {
		for (int i=0;i<=N;i++) bit[i]=-inf;
	}
	void update(int idx,int val) {
		while (idx<=N) {
			bit[idx]=max(bit[idx],val);
			idx+=(idx&(-idx));
		}
	}
	int get(int idx) {
		int mx=-inf;
		while (idx>0) {
			mx=max(mx,bit[idx]);
			idx-=(idx&(-idx));
		}
		return mx;
	}
} tree;
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>c>>d;
    for (int i=1;i<=n;i++) {
    	int b,p;
    	char c;
    	cin>>b>>p>>c;
    	if (c=='C') vc.push_back({p,b});
    	else vd.push_back({p,b});
    } 
    sort(vc.begin(),vc.end());
    sort(vd.begin(),vd.end());
    int mx1=-inf,mx2=-inf;
    tree.reset();
    for (auto [p,b]:vc) {
    	if (p>c) break;
    	res=max(res,b+tree.get(c-p));
    	tree.update(p,b);
    	mx1=max(mx1,b);
    }
    tree.reset();
    for (auto [p,b]:vd) {
    	if (p>d) break;
    	res=max(res,b+tree.get(d-p));
    	tree.update(p,b);
    	mx2=max(mx2,b);
    }
    res=max(res,mx1+mx2);
    cout<<res;
}