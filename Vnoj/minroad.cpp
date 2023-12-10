#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,a,b,res=-1;
pair<int,int>p[N+5];
bool check(int dif) {
	int r=0,ca=0,cb=0;
	for (int l=1;l<=n;l++) {
		while (p[r+1].first-p[l].first<=dif&&r<n) {
			if (p[r+1].second==1) ca++;
			else cb++;
			r++;
		}
		if (ca>=a&&cb>=b) return true;
		if (p[l].second==1) ca--;
		else cb--;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    int lo=1,hi=1e9;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
	cout<<res;
}