#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int d[N+5];
int t;
int a,b,c;
map<int,int>ma,mb,mc,mx;
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]!=i) continue;
		for (int j=i*2;j<=N;j+=i) d[j]=i;
	}
}
int main() {
	freopen("MINX.INP","r",stdin);
	freopen("MINX.OUT","w",stdout);
	seive();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	long long res=1;
    	ma.clear();
    	mb.clear();
    	mc.clear();
    	mx.clear();
    	cin>>a>>b>>c;
    	int ta=a;
    	while (ta!=1) {
    		ma[d[ta]]++;
    		ta/=d[ta];
    	}
    	int tb=b;
    	while (tb!=1) {
    		mb[d[tb]]++;
    		tb/=d[tb];
    	}
    	int tc=c;
    	while (tc!=1) {
    		mc[d[tc]]++;
    		tc/=d[tc];
    	}
    	for (auto i=ma.begin();i!=ma.end();i++) {
    		int fi=i->first,se=i->second;
    		if (mc[fi]+mx[fi]<se) mx[fi]+=se-mc[fi]-mx[fi]; 
    	}
    	for (auto i=mb.begin();i!=mb.end();i++) {
    		int fi=i->first,se=i->second;
    		if (ma[fi]+mx[fi]<se) mx[fi]+=se-ma[fi]-mx[fi]; 
    	}
    	for (auto i=mc.begin();i!=mc.end();i++) {
    		int fi=i->first,se=i->second;
    		if (mb[fi]+mx[fi]<se) mx[fi]+=se-mb[fi]-mx[fi]; 
    	}
    	for (auto i=mx.begin();i!=mx.end();i++) {
    		int fi=i->first,se=i->second;
    		while (se--) res*=fi;
    	}
    	cout<<res<<'\n';
    }
}