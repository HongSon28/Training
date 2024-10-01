#include<bits/stdc++.h>
using namespace std;
long long l,r,k;
string res;
long long calc(long long a,long long b) {
	return a/b+(a%b!=0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (cin>>l>>r>>k) {
    	res="~";
    	for (long long i=1;i<=r;i*=10) {
    		long long t=calc(max(i,l),k)*k;
    		if (t<=r) res=min(res,to_string(t));
    	}
    	if (res=="~") cout<<-1<<'\n';
    	else cout<<res<<'\n';
    }
}