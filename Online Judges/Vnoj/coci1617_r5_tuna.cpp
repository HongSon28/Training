#include<bits/stdc++.h>
using namespace std;
int n,x,res;
int p1,p2,p3;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>x;
	for (int i=1;i<=n;i++) {
		cin>>p1>>p2;
		if (abs(p1-p2)>x) {
			cin>>p3;
			res+=p3;
		} else res+=max(p1,p2);
	}
	cout<<res;
}