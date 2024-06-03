#include<bits/stdc++.h>
using namespace std;
int n,m,res;
pair<long long,long long>a[12];
long long ccw(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3) {
	long long a1=p2.first-p1.first;
	long long b1=p2.second-p1.second;
	long long a2=p3.first-p2.first;
	long long b2=p3.second-p2.second;
	long long t=a1*b2-a2*b1;
	if (t==0) return 0;
	if (t<0) return -1;
	return 1;
}
bool check(pair<long long,long long>p) {
	for (int i=1;i<=n;i++) {
		if (ccw(a[i],a[i+1],p)>0) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    a[n+1]=a[1];
    for (int i=1;i<=m;i++) {
    	long long x,y;
    	cin>>x>>y;
    	res+=check({x,y});
    }
    cout<<res;
}