#include<bits/stdc++.h>
using namespace std;
long long t,a,s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>a>>s;
		long long dif=s-2*a;
		if (dif>=0&&(dif&a)==0) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}