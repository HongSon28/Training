#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	int mnx=INT_MAX,mxx=INT_MIN,mny=mnx,mxy=mxx;
    	for (int i=1;i<=4;i++) {
    		cin>>x>>y;
    		mnx=min(mnx,x);
    		mxx=max(mxx,x);
    		mny=min(mny,y);
    		mxy=max(mxy,y);
    	}
    	cout<<(mxx-mnx)*(mxy-mny)<<'\n';
    }
}