#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5],pos[N+5],sum[N+5];
vector<vector<pair<int,int>>>v(N+5);
int res,ru,rv;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]]=i;
		sum[i]=sum[i-1]+(a[i]==i);
		v[i+a[i]].push_back({min(i,a[i]),max(i,a[i])});
	}
	for (int i=1;i<=2*n;i++) {
		sort(v[i].begin(),v[i].end(),greater<pair<int,int>>());
		for (int j=0;j<(int)v[i].size();j++) {
			int x=v[i][j].first,y=v[i][j].second;
			int temp=j+1+sum[x-1]+sum[n]-sum[y];
			if (res<temp) {
				res=temp;
				ru=x,rv=y;
			}
		}
	}
	cout<<a[ru]<<' '<<a[rv];
}