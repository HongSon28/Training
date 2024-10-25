#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int t,n,c;
pair<int,int>p[N+5];
int l[N+5],r[N+5];
vector<int>cprs;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n;
    	int res=n;
    	cprs.clear();
    	for (int i=0;i<=2*n+2;i++) l[i]=r[i]=0;
    	for (int i=1;i<=n;i++) {
    		cin>>p[i].first>>p[i].second;
    		cprs.push_back(p[i].first);
    		cprs.push_back(p[i].second);
    	}
    	sort(cprs.begin(),cprs.end());
    	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    	for (int i=1;i<=n;i++) {
    		p[i].first=lower_bound(cprs.begin(),cprs.end(),p[i].first)-cprs.begin()+1;
    		p[i].second=lower_bound(cprs.begin(),cprs.end(),p[i].second)-cprs.begin()+1;
    		l[p[i].second]++;
    		r[p[i].first]++;
    	}
    	for (int i=1;i<=2*n+1;i++) l[i]+=l[i-1];
    	for (int i=2*n;i>=0;i--) r[i]+=r[i+1];
    	for (int i=1;i<=n;i++) {
    		//cout<<p[i].first<<' '<<p[i].second<<' '<<l[p[i].first-1]<<' '<<r[p[i].second+1]<<endl;
    		int cur=l[p[i].first-1]+r[p[i].second+1];
    		res=min(res,cur);
    	}
    	cout<<res<<'\n';
    }	
}