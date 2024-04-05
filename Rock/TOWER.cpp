#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,test;
struct block {
	long long x,y,z;
	bool operator < (const block &other) const {
		if (x!=other.x) return x<other.x;
		if (y!=other.y) return y<other.y;
		return z<other.z;
	}
};
long long temp[3],inf=1e18;
long long dp1[N],dp2[N];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	while (cin>>n) {
		test++;
		if (n==0) return 0;
		int m=0;
		vector<block>v;
		vector<int>cprs;
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for (int i=1;i<=n;i++) {
			cin>>temp[0]>>temp[1]>>temp[2];
			sort(temp,temp+3);
			do {
				v.push_back({temp[0],temp[1],temp[2]});
				cprs.push_back(temp[1]);
			} while (next_permutation(temp,temp+3));
		}
		sort(cprs.begin(),cprs.end());
		cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
		for (int i=0;i<(int)v.size();i++) {
			v[i].y=lower_bound(cprs.begin(),cprs.end(),v[i].y)-cprs.begin()+1;
			m=max(m,(int)v[i].y);
		}
		v.push_back({inf,inf,inf});
		sort(v.begin(),v.end());
		for (int i=0;i<(int)v.size()-1;i++) {
			dp2[v[i].y]=max(dp2[v[i].y],dp1[v[i].y-1]+v[i].z);
			//cout<<v[i].x<<' '<<v[i].y<<' '<<v[i].z<<endl;
			if (v[i].x!=v[i+1].x) {
				for (int j=1;j<=m;j++) {
					dp1[j]=max({dp1[j],dp2[j],dp1[j-1]});
					dp2[j]=0;
					//cout<<dp1[j]<<' ';
				}
				//cout<<'\n';
			}
		}
		cout<<"Case "<<test<<": maximum height = "<<dp1[m]<<'\n';
	}
}