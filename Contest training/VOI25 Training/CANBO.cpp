#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,x;
long long k;
pair<long long,long long>p[N+5];
long long res;
bool check(long long t) {
	vector<long long>cur;
	for (int i=1;i<=n;i++) {
		if (p[i].first<=t) break;
		cur.push_back((p[i].first-t)*p[i].second);
	}
	int cnt=cur.size()-(x-1);
	if (cnt<=0) return true;
	long long sum=0;
	sort(cur.begin(),cur.end());
	for (int i=0;i<cnt;i++) sum+=cur[i];
	return sum<k;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>x;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n,greater<pair<long long,long long>>());
    long long lo=0,hi=1e9;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<res;
}