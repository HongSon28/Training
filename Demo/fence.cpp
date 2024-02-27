#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<long long,long long>p[N+5];
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
	if (a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
long long mx1[N+5],mx2[N+5],sum[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].first;
    for(int i=1;i<=n;i++) cin>>p[i].second;
    sort(p+1,p+1+n,comp);
    mx1[0]=-1e17;
    for (int i=1;i<=n;i++) {
    	mx1[i]=max(mx1[i-1],p[i].second-p[i].first);
    	sum[i]=sum[i-1]+p[i].first;
    }
    mx2[n+1]=-1e17;
    for (int i=n;i>=1;i--) mx2[i]=max(mx2[i+1],p[i].second);
	for (int i=1;i<=n;i++) {
		cout<<max(sum[i-1]+mx2[i],sum[i]+mx1[i])<<' ';
	}
}