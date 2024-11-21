#include<bits/stdc++.h>
using namespace std;
int t,a,b,c;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>a>>b>>c;
    	if (a>0) cout<<"CURVE UP"<<'\n';
    	else if (a<0) cout<<"CURVE DOWN"<<'\n';
    	else cout<<"NO CURVE"<<'\n';
    }
}