#include<bits/stdc++.h>
using namespace std;
long long n;
long long g[51];
int res,lo=1,hi=50;
void init() {
	g[1]=1;
	g[2]=2;
	for (int i=3;i<=hi;i++) g[i]=g[i-1]+g[i-2];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    init();
    cin>>n;
    if (n==1) {
    	cout<<0;
    	return 0;
    }
    while (lo<=hi) {
    	int mid=(lo+hi)/2;
    	if (g[mid]>=n) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<res;
}