#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m;
long long A,B,C;
struct train{
	long long u,v,l,r;
	bool operator < (const train &other) const {
		if (l!=other.l) return l<other.l;
		return r<other.r;
	}
} x[N+5];
long long dp[N+5],inf=1e18,res=inf;
struct ConvexHull{
	vector<long long>a,b;
	vector<int>line;
	vector<long double>point;
	double f(int x,int y) {
		return (long double) (b[y]-b[x])/(a[x]-a[y]);
	}
	void add(long long A,long long B) {
		a.push_back(A);
		b.push_back(B);
		int i=a.size()-1;
		while ((int)line.size()>1 || ((int)line.size()==1&&a[line.back()]==A)) {
			if (a[line.back()]==A) {
				if (b[line.back()]>b[i]) {
					line.pop_back();
					if (!line.empty()) point.pop_back();
				} else break;
			} else {
				if (f(i,line.back()) <= f(i,line[line.size()-2])) {
					line.pop_back();
					if (!line.empty()) point.pop_back();
				} else break;
			}
		}
		if (line.empty() || a[line.back()]!=A) {
			if (!line.empty()) point.push_back(f(i,line.back()));
			line.push_back(i);
		}
	}
	long long get(long long X) {
		int j=lower_bound(point.begin(),point.end(),X)-point.begin();
		if ((int)a.size()<=j-1) return inf;
		return a[line[j-1]]*X+b[line[j-1]];
	}
} CHT[N+5];
vector<int>in[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>A>>B>>C;
    for (int i=1;i<=m;i++) cin>>x[i].u>>x[i].v>>x[i].l>>x[i].r;
    sort(x+1,x+1+m);
    for (int i=1;i<=m;i++) {
    	CHT[i].point.push_back(-inf);
    	dp[i]=inf;
    	in[x[i].r].push_back(i);
    }
    in[1].push_back(0);
    x[0].v=1;
    x[0].l=-1;
    for (int i=1;i<=m;i++) {
    	long long cur=A*x[i].l*x[i].l+B*x[i].l+C;
    	for (int j=x[i-1].l+1;j<=x[i].l;j++) {
    		if (in[j].empty()) continue;
    		for (auto k:in[j]) {
    			CHT[x[k].v].add(-2*A*x[k].r,A*x[k].r*x[k].r-B*x[k].r+dp[k]);
    		}
    	}

    	dp[i]=min(dp[i],CHT[x[i].u].get(x[i].l)+cur);
    	//cout<<x[i].u<<' '<<x[i].v<<' '<<x[i].l<<' '<<x[i].r<<' '<<CHT[x[i].u].get(x[i].l)<<' '<<cur<<' '<<dp[i]<<endl;
    	if (x[i].v==n) res=min(res,dp[i]+x[i].r*A); 
    }
    cout<<res;
}