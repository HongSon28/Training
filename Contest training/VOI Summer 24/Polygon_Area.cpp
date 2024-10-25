#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
pair<long long,long long>p[N+5];
long long res;
long long calc(pair<long long,long long>x,pair<long long,long long>y,pair<long long,long long>z) {
	y.first-=x.first,y.second-=x.second;
	z.first-=x.first,z.second-=x.second;
	return y.first*z.second-y.second*z.first;	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	for (int i=1;i<n-1;i++) res+=calc(p[n],p[i],p[i+1]);
	cout<<abs(res);
}