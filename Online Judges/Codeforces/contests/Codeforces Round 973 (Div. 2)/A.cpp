#include<bits/stdc++.h>
using namespace std;
int t,n,x,y;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>x>>y;
    	int k=min(x,y);
    	cout<<(n+k-1)/k<<'\n';
    }
}