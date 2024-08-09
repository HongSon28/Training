#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=2e3;
int n,d,res;
int a[N+5];
map<int,vector<pair<int,int>>>mp;
int main() {
	//freopen("PAIR.INP","r",stdin);
	//freopen("PAIR.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) 
    	for (int j=i+1;j<=n;j++) mp[a[i]+a[j]].push_back({i,j});
	for (auto it=mp.begin();it!=mp.end();it++) {
		long long s=it->first;
		vector<int>pos;
		for (auto p:mp[s]) {
			pos.push_back(p.first);
			pos.push_back(p.second);
		}
		if (d==1&&mp.count(s+1)!=0) {
			for (auto p:mp[s+1]) {
				pos.push_back(p.first);
				pos.push_back(p.second);
			}
		}
		sort(pos.begin(),pos.end());
		int i=0,j=pos.size()-1,cnt=0;
		while (i<j) {
			while (i>0&&pos[i]==pos[i-1]) i++;
			while (j<(int)pos.size()-1&&pos[j]==pos[j+1]) j--;
			if (i>=j) break;
			if (a[pos[i]]+a[pos[j]]==s||a[pos[i]]+a[pos[j]]==s+d) {
				//cout<<i<<' '<<j<<' '<<a[pos[i]]<<' '<<a[pos[j]]<<' '<<s<<endl;
				cnt++;
				i++;
				j--;
			} else if (a[pos[i]]+a[pos[j]]<s) i++;
			else j--;
		}
		res=max(res,cnt);
	}
	cout<<res;
}