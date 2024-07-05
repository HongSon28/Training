#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<long long, long long> p[N+5];
vector<pair<long long,long long>>b(N+1,{1e9+1,1});
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first;
    for (int i=1;i<=n;i++) cin>>p[i].second;
    b[0]={-1,1};
    auto cmp=[&](pair<long long,long long>x,pair<long long,long long>y) {
    	return x.first*y.second<x.second*y.first;
	};
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),p[i],cmp)-b.begin();
        b[k]=p[i];
        res=max(res,k);
    }
    cout<<res;
}

