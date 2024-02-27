#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,q;
int a[N+5],b[N+5];
vector<int>pos;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	pos.clear();
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	a[n+1]=a[n];
    	for (int i=1;i<=n;i++) {
    		if (a[i]!=a[i+1]) pos.push_back(i);
    	}
    	cin>>q;
    	while (q--) {
    		int l,r;
    		cin>>l>>r;
    		if (pos.empty()||l>pos.back()) {
    			cout<<"-1 -1"<<'\n';
    			continue;
    		}
    		int temp=*lower_bound(pos.begin(),pos.end(),l);
    		if (temp<r) cout<<temp<<' '<<temp+1<<'\n';
    		else cout<<"-1 -1"<<'\n';
    	}
    	cout<<'\n';
    }
}