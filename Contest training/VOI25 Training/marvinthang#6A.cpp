#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
pair<long long,long long>p[N+5];
vector<pair<long long,long long>>vc;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first>>p[i].second;
    	p[i].first/=2;
    	p[i].second/=2;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
    	while (!vc.empty()&&vc.back().second<=p[i].second) vc.pop_back();
    	vc.push_back(p[i]);
    }
    long long res=0;
    long long cur=0;
    for (auto [x,y]:vc) {
    	res+=y*(x-cur);
    	cur=x;
    }
    cout<<res*4;
}