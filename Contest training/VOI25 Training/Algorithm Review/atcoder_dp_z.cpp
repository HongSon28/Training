#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long c,h[N+5],dp[N+5];
struct ConvexHullTrick{
	vector<long long>a,b;
	vector<int>line;
	vector<long double>point;
	void init() {
		a.resize(n+2),b.resize(n+2);
		point.push_back(0);
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
			if (!line.empty()) point.push_back(f(line.back(),i));
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
    cin>>n>>c;
    for (int i=1;i<=n;i++) cin>>h[i];
    dp[1]=0;
    cht.init();
    cht.add(-2*h[1],h[1]*h[1],1);
    for (int i=2;i<=n;i++) {
    	dp[i]=cht.get(h[i])+h[i]*h[i]+c;
    	//cout<<cht.get(h[i])<<' '<<dp[i]<<endl;
    	cht.add(-2*h[i],h[i]*h[i]+dp[i],i);
    }
    cout<<dp[n];
}