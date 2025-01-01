#include<bits/stdc++.h>
using namespace std;
int t;
long long a[4],b[4];
long long cross(long long x1,long long y1,long long x2,long long y2) {
	return x1*y2-x2*y1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	for (int i=1;i<=3;i++) cin>>a[i]>>b[i];
    	long long c=cross(a[2]-a[1],b[2]-b[1],a[3]-a[1],b[3]-b[1]);
    	if (c>0) cout<<"LEFT"<<'\n';
    	else if (c<0) cout<<"RIGHT"<<'\n';
    	else cout<<"TOUCH"<<'\n';
    }
}