#include<bits/stdc++.h>
using namespace std;
int t,n;
string x,y;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>x>>y;
    	int c0=0,c1=0,c2=0;
    	x=' '+x,y=' '+y;
    	for (int i=1;i<=n;i++) {
    		if (x[i]=='1'&&x[i]==y[i]) c0++;
    		if (x[i]=='1') c1++;
    		if (y[i]=='1') c2++;
    	}
    	if (c1==c2) cout<<c2-c0<<'\n';
    	else if (c1<c2) cout<<c2-c0<<'\n';
    	else cout<<c1-c0<<'\n';
    }
}