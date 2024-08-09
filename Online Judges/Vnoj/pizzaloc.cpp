#include<bits/stdc++.h>
using namespace std;
const int N=100;
int k,m,n;
double r;
pair<int,int>p1[N+5],p2[N+5];
int s[N+5],res;
bool used[N+5];
double dist(pair<int,int>x,pair<int,int>y) {
	double t1=(x.first-y.first)*(x.first-y.first);
	double t2=(x.second-y.second)*(x.second-y.second);
	return sqrt(t1+t2);
}
void calc() {
	int cur=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (!used[j]) continue;
			if (dist(p1[j],p2[i])<=r) {
				cur+=s[i];
				break;
			}
		}
	}
	res=max(res,cur);
}
void rec(int t,int last) {
	for (int i=last+1;i<=m-(k-t);i++) {
		used[i]=true;
		if (t==k) calc();
		else rec(t+1,i);
		used[i]=false;
	}
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>k>>r>>m;
    for (int i=1;i<=m;i++) cin>>p1[i].first>>p1[i].second;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p2[i].first>>p2[i].second>>s[i];
    rec(1,0);
    cout<<res;
}