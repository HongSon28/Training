#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
string s;
int n;
long long base=311,mod=1e9+7,hs[N+5],pw[N+5];
void create() {
	pw[0]=1;
	for (int i=1;i<=n;i++) {
		pw[i]=pw[i-1]*base%mod;
		hs[i]=(hs[i-1]*base+(int)s[i])%mod;
	}
}
long long get(int l,int r) {
	return (hs[r]-hs[l-1]*pw[r-l+1]+mod*mod)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    int m;
    if (n%2) m=(n+1)/2;
    else m=n/2+1;
    create();
    for (int i=m;i<n;i++) {
    	if (get(1,i)==get(n-i+1,n)) {
    		cout<<"YES"<<'\n'<<s.substr(1,i);
    		return 0;
    	}
    }
    cout<<"NO";
}