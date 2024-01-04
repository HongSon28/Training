#include<bits/stdc++.h>
using namespace std;
long long fib[101];
int t;
long long n,k;
void prep() {
	fib[1]=fib[2]=1;
	for (int i=3;i<=100;i++) fib[i]=fib[i-1]+fib[i-2];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	bool flag=true;
    	for (int i=1;i<=n;i++) {
    		if (fib[i]>k) {
    			flag=false;
    			break;
    		} 
    	}
    	if (flag) cout<<"yes"<<'\n';
    	else cout<<"no"<<'\n';
    }	
}