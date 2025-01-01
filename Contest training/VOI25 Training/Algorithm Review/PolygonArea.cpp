#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
long long x[N+5],y[N+5],res;
long long cross(long long x1,long long y1,long long x2,long long y2) {
	return x1*y2-x2*y1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<n-1;i++) res+=cross(x[i+1]-x[i],y[i+1]-y[i],x[n]-x[i],y[n]-y[i]);
    cout<<abs(res);
}