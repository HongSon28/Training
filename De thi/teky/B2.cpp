#include<bits/stdc++.h>
using namespace std;
long long k;
long long cur=9;
long long power(long long x,long long y) {
	long long ans=1;
	while (y--) ans*=x;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>k;
    for (long long num=1;;num++) {
    	if (k>cur*num) {
    		k-=cur*num;
    		cur*=10;
    	} else {
    		long long st=power(10,num-1);
    		long long p;
    		if (k%num==0) {
    			p=st+k/num-1;
    			k-=(k/num-1)*num;
    			string t=to_string(p);
    			cout<<t[k-1];
    		} else {
    			p=st+k/num;
    			k-=(k/num)*num;
    			string t=to_string(p);
    			cout<<t[k-1];
    		}
    		break;
    	}
    }
}