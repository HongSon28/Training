#include<bits/stdc++.h>
using namespace std;
unsigned long long C(int k,int n) {
	if (k>n) return 0;
	int j=1;
	unsigned long long res=1,cur=1;
	for (unsigned long long i=k+1;i<=n;i++) {
		res*=i;
		unsigned long long temp=__gcd(res,cur);
		res/=temp;
		cur/=temp;
		if (cur==1) {
			j++;
			if (j>n-k) cur=1;	
			else cur=j;
		}
	}
	return res;
}
unsigned long long n,m,t,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>t;
    for (int i=4;i<=n;i++) {
    	int g=t-i;
    	if (g<1) break;
    	res+=C(i,n)*C(g,m);
    }
    cout<<res;
}
