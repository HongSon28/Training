#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,q,inf=1e9;
int c1[N+5],c2[N+5];
vector<int>v[5][5];
int calc(int x,int y,int col1,int col2) {
	if (col1>col2) swap(col1,col2);
	int ans=inf;
	int pos=-1;
	int lo=0,hi=v[col1][col2].size()-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (v[col1][col2][mid]>=x) {
			pos=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	if (pos!=-1) {
		int temp=v[col1][col2][pos];
		ans=abs(temp-x)+abs(temp-y);
	}
	pos=-1;
	lo=0,hi=v[col1][col2].size()-1;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (v[col1][col2][mid]<=x) {
			pos=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	if (pos!=-1) {
		int temp=v[col1][col2][pos];
		ans=min(ans,abs(temp-x)+abs(temp-y));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>q;
    	for (int i=1;i<=4;i++)
    		for (int j=1;j<=4;j++)
    			v[i][j].clear();
    	for (int i=1;i<=n;i++) {
    		string s;
    		cin>>s;
    		if (s[0]=='B') c1[i]=1;
    		else if (s[0]=='G') c1[i]=2;
    		else if (s[0]=='R') c1[i]=3;
    		else c1[i]=4;
    		if (s[1]=='B') c2[i]=1;
    		else if (s[1]=='G') c2[i]=2;
    		else if (s[1]=='R') c2[i]=3;
    		else c2[i]=4;
    		v[c1[i]][c2[i]].push_back(i);
    	}
    	while (q--) {
    		int x,y;
    		cin>>x>>y;
    		if (x>y) swap(x,y);
    		if (c1[x]==c1[y]||c1[x]==c2[y]||c2[x]==c1[y]||c2[x]==c2[y]) {
    			cout<<y-x<<'\n';
    			continue;
    		}
    		int res=inf;
    		for (int i=1;i<=4;i++) {
    			if (c1[x]!=i&&c2[x]!=i) continue;
    			for (int j=1;j<=4;j++) {
    				if (c1[y]!=j&&c2[y]!=j) continue;
    				res=min(res,calc(x,y,i,j));
    			}
    		}
    		if (res==inf) cout<<-1<<'\n';
    		else cout<<res<<'\n';
    	}
    }
}