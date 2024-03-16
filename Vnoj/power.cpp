#include<bits/stdc++.h>
using namespace std;
long long l,r,res;
bool check(long long k) {
	for (int i=2;;i++) {
		if (pow(i,k)>=l) {
			if (pow(i,k)<=r) return true;
			else return false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++) {
    	res=1;
	    cin>>l>>r;
	    for (long long i=2;i<=40;i++) {
	    	if (check(i)) res=i;
	    }
	    cout<<"Case #"<<tt<<": "<<res<<'\n';
	}
}