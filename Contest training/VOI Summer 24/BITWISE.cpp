#include<bits/stdc++.h>
using namespace std;
int q,type;
unsigned long long x,y,v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
	while (q--) {
		cin>>type;
		if (type==1) {
			cin>>x>>y;
			cout<<(x&y)<<'\n';
		} else if (type==2) {
			cin>>x>>y;
			cout<<(x|y)<<'\n';
		} else if (type==3) {
			cin>>x>>y;
			cout<<(x^y)<<'\n';
		} else if (type==4) {
			cin>>x>>y;
			cout<<(x<<y)<<'\n';
		} else if (type==5) {
			cin>>x>>y;
			cout<<(x>>y)<<'\n';
		} else if (type==6) {
			cin>>x>>y;
			cout<<(x>>y&1)<<'\n'; 
		} else {
			int i;
			cin>>x>>i>>v;
			if (v==0) x&=(~(1ll<<i));
			else x|=(1ll<<i);
			cout<<x<<'\n';
		}
	}
}