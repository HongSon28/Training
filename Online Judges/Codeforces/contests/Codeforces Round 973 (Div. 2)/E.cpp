#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5],b[N+5],c[N+5];
long long res;
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) {
			for (int j=i*i;j<=N;j+=i) 
				if (d[j]>i) d[j]=i;
		}
	}
}
vector<int>v[N+5];
bool used[N+5];
multiset<pair<int,int>>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	sort(a+1,a+1+n);
    	for (int i=1;i<=n;i++) {
    		used[i]=false;
    		c[i]=a[i];
    	}
    	s.clear();
    	for (int i=1;i<=a[n];i++) v[i].clear();
    	for (int i=2;i<=n;i++) {
    		int t=a[i];
    		while (t>1) {
    			int div=d[t];
    			v[div].push_back(i);
    			while (t%div==0) t/=div;
    		}
    		s.insert({a[i],i});
    	}
    	used[1]=true;
    	res=a[1];
    	b[1]=a[1];
    	int last=a[1];
    	for (int i=2;i<=n;i++) {
    		int t=b[i-1];
    		while (t>1) {
    			int div=d[t];
				vector<int>temp=v[div];
				v[div].clear();
				for (auto p:temp) {
					if (used[p]) continue;
					//cout<<i<<' '<<div<<' '<<p<<' '<<a[p]<<endl;
					s.erase(s.lower_bound({a[p],p}));
					a[p]=a[p]/__gcd(a[p],b[i-1]);
					s.insert({a[p],p});
					//cout<<a[p]<<endl;
					if (a[p]%div==0) v[div].push_back(p);
				}
    			while (t%div==0) t/=div;
    		}
    		pair<int,int>temp=*s.begin();
    		b[i]=c[temp.second];
    		s.erase(s.begin());
    		used[temp.second]=true;
    		last=__gcd(last,c[temp.second]);
    		res+=last;
    		cout<<i<<' '<<temp.second<<' '<<b[i]<<endl;
    	}
    	cout<<res<<'\n';
    }
}