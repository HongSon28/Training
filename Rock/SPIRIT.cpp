#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int res;
int calc(int x,int y) {
	int d=y-x;
	if (d%2==0) return d/2;
	return d/2+1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b>>c;
    int t=(a/c+1)*c;
    if (t>b) {
    	cout<<calc(a,b);
    	return 0;
    }
    res+=calc(a,t-1)+1;
    a=t+1;
    if (a==b) {
    	cout<<res;
    	return 0;
    }
    int cost=calc(1,c-1)+1;
    int fi=t,ls=(b/c)*c;
    int cnt=(ls-fi)/c;
    res+=cnt*cost;
    a=ls+1;
    res+=calc(a,b);
    cout<<res;
}