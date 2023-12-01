#include<bits/stdc++.h>
using namespace std;
int t;
long long n,sum,s;
int main() {
	cin>>t;
	while (t--) {
		cin>>n>>s;
		sum=n*(n+1)/2;
		s=abs(s);
		if (((s%2)==(sum%2))&&(s<=sum)) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}	
}