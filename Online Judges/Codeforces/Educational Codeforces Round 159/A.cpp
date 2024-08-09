#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	int c0=0,c1=0;
    	bool flag=false;
    	cin>>n>>s;
    	for (int i=0;i<n;i++) {
    		if (s[i]=='0') c0++;
    		else c1++;
    	}
    	if (c0>c1) {
    		cout<<"YES"<<'\n';
    		continue;
    	}
    	for (int i=1;i<n;i++) {
    		if (s[i-1]!=s[i]) {
    			flag=true;
    			break;
    		}
    	}
    	if (flag) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}