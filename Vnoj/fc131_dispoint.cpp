#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,x[N+5],y[N+5],x2[N+5],y2[N+5],mn_x=INT_MAX,mn_y=INT_MAX,mx_x=INT_MIN,mx_y=INT_MIN;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=n;i++) cin>>y[i];
    for (int i=1;i<=n;i++) {
    	x2[i]=x[i]+y[i];
    	y2[i]=y[i]-x[i];
    	mn_x=min(mn_x,x2[i]);
    	mn_y=min(mn_y,y2[i]);
    	mx_x=max(mx_x,x2[i]);
    	mx_y=max(mx_y,y2[i]);
    }
    for (int i=1;i<=n;i++) {
    	int a=max(abs(x2[i]-mn_x),abs(x2[i]-mx_x));
    	int b=max(abs(y2[i]-mn_y),abs(y2[i]-mx_y));
    	cout<<max(a,b)<<' ';
    }
}