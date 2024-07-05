#include<bits/stdc++.h>
using namespace std;
int t,c,n,m;
struct dat{
	int type,x,d; 
	bool operator < (const dat &other) const {
		return x<other.x;
	}
};
int main() {
	freopen("pepsi.inp","r",stdin);
	freopen("pepsi.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	vector<dat>vc;
    	long long res=0;
    	cin>>c>>m>>n;
    	long long cur=c;
    	for (int i=1;i<=m;i++) {
    		int temp;
    		cin>>temp;
    		vc.push_back({1,temp,0});
    	}
    	for (int i=1;i<=n;i++) {
    		int x,d;
    		cin>>x>>d;
    		vc.push_back({2,x,d});
    	}
    	sort(vc.begin(),vc.end());
    	for (auto [type,x,d]:vc) {
    		if (type==1) cur=c;
    		else {
    			if (cur>=d) {
    				cur-=d;
    				res+=d;
    			}
    		}
    	}
    	cout<<res<<'\n';
    }
}