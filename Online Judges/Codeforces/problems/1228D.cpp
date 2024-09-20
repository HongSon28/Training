#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m;
int a[N+5][8];
vector<int>ms;
bool msk[(1<<8)];
vector<pair<int,int>>mask;
pair<int,int> check(int k) {
	mask.clear();
	for (int i=0;i<(1<<m);i++) msk[i]=false;
	for (int i=1;i<=n;i++) {
		int cur=0;
		for (int j=0;j<m;j++) 
			if (a[i][j]>=k) 
				cur|=(1<<j);
		//cout<<cur<<endl;
		if (!msk[cur]) {
			msk[cur]=true;
			mask.push_back({cur,i});
		}
	}
	for (int i=0;i<(int)mask.size();i++) {
		for (int j=0;j<(int)mask.size();j++)
			if ((mask[i].first|mask[j].first)==(1<<m)-1) return {mask[i].second,mask[j].second};
	}
	return {-1,-1};
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=0;j<m;j++)
			cin>>a[i][j];
	pair<int,int>res={1,1};
	int lo=1,hi=1e9;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		pair<int,int>temp=check(mid);
		if (temp!=make_pair(-1,-1)) {
			res=temp;
			lo=mid+1;
		} else hi=mid-1;
	}
	cout<<res.first<<' '<<res.second;
}