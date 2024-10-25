#include<bits/stdc++.h>
using namespace std;
const int N=5e5,SZ=sqrt(N);
int n,q;
int a[N+5];
int cnt[N+5],cur,res[N+5];
struct query{
	int l,r,id;
	bool operator < (const query &other) const {
		return make_pair(l/SZ,r)<make_pair(other.l/SZ,other.r);
	}
}qu[N+5];
void add(int x) {
	if (cnt[x]==1) cur++;
	else if (cnt[x]==2) cur--;
	cnt[x]++;
}
void remove(int x) {
	if (cnt[x]==2) cur--;
	else if (cnt[x]==3) cur++;
	cnt[x]--;
}
vector<int>cprs;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].l>>qu[i].r;
    	qu[i].id=i;
    }
    sort(qu+1,qu+1+q);
    int l=1,r=1;
    cnt[a[1]]++;
    for (int i=1;i<=q;i++) {
    	while (r<qu[i].r) {
    		r++;
    		add(a[r]);
    		//cout<<"add "<<r<<' '<<cur<<endl;
    	}
    	while (r>qu[i].r) {
    		remove(a[r]);
    		//cout<<"remove "<<r<<' '<<cur<<endl;
    		r--;
    	}
    	while (l>qu[i].l) {
    		l--;
    		add(a[l]);
    		//cout<<"add "<<l<<' '<<cur<<endl;
    	}
    	while (l<qu[i].l) {
    		remove(a[l]);
    		//cout<<"remove "<<l<<' '<<cur<<endl;
    		l++;
    	}
    	//cout<<qu[i].id<<' '<<cur<<endl;
    	res[qu[i].id]=cur;
    }
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}