#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,p,res;
vector<int>v[N+5];
bool check(int t) {
	int cnt=0;
	for (int i=1;i<=p;i++) {
		for (auto x:v[i]) cnt+=(x<=t);
	}
	return (cnt>=m);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++) {
    	int a,b;
    	cin>>a>>b;
    	v[a].push_back(b);
    }	
    for (int i=1;i<=p;i++) {
    	for (int j=0;j<v[i].size();j++) v[i][j]-=i-1;
    }
    int lo=0,hi=1e9;
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (check(mid)) {
    		hi=mid-1;
    		res=mid;
    	} else lo=mid+1;
    } 
    cout<<res;
}