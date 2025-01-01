#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],b[N+5],dp[N+5];
struct ConvexHullTrick{
	vector<int>line;
	vector<long double>point;
	vector<long long>a,b;
	void init() {
		point.push_back(0);
		a.resize(n+2),b.resize(n+2);
	}
	long double f(int x,int y) {
		return (long double)1.0*(b[y]-b[x])/(a[x]-a[y]);
	}
	void add(long long A,long long B,int i) {
		a[i]=A,b[i]=B;
		while (line.size()>1||(line.size()==1&&a[line.back()]==a[i])) {
			if (line.size()==1) {
				if (b[line.back()]>b[i]) {
					line.pop_back();
					if (!line.empty()) point.pop_back();
				} else break;
			} else {
				if (f(i,line.back())<=f(i,line[line.size()-2])) {
					line.pop_back();
					if (!line.empty()) point.pop_back();
				} else break;
			}
		}
		if (line.empty()||a[line.back()]!=a[i]) {
			if (!line.empty()) point.push_back(f(i,line.back()));
			line.push_back(i);
		}
	}
	long long get(int x) {
		int i=lower_bound(point.begin(),point.end(),x)-point.begin();
		return a[line[i-1]]*x+b[line[i-1]];
	}
} cht;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	cht.init();
	cht.add(b[1],0,1);
	for (int i=2;i<=n;i++) {
		dp[i]=cht.get(a[i]);
		cht.add(b[i],dp[i],i);
	}
	cout<<dp[n];
}