#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],b[N+5],cur;
vector<pair<int,int>>v;
long long res=1,mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	v.push_back({a[i],1});
    }
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	v.push_back({b[i],0});
    }
    sort(v.begin(),v.end());
    for (auto [x,id]:v) {
    	if (id==1) {
    		if (cur<0) {
    			res*=-cur;
    			res%=mod;
    		}
    		cur++;
    	} else {
    		if (cur>0) {
    			res*=cur;
    			res%=mod;
    		}
    		cur--;
    	}
    }
    cout<<res;
}