#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int b[N+5],r[N+5],res=INT_MAX;
vector<pair<int,int>>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	v.push_back({b[i],0});
    }
    for (int i=1;i<=n;i++) {
    	cin>>r[i];
    	v.push_back({r[i],1});
    }
    sort(v.begin(),v.end());
    for (int i=1;i<(int)v.size();i++) {
    	if (v[i].second!=v[i-1].second) {
    		res=min(res,v[i].first-v[i-1].first);
    	}
    }
    cout<<res;
}