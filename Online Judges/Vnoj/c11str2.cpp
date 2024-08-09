#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long base=311,mod=1e9+7;
long long power[N+5],hasha[N+5],hashb[N+5];
string a,b;
int n,m,res;
void create_hash() {
	power[0]=1;
	for (int i=1;i<=N;i++) power[i]=power[i-1]*base%mod;
	for (int i=1;i<=n;i++) hasha[i]=(hasha[i-1]*base+(int)a[i])%mod;
	for (int i=1;i<=m;i++) hashb[i]=(hashb[i-1]*base+(int)b[i])%mod;
}
bool check(int x,int y,int u,int v) {
	long long hash1=(hasha[y]-hasha[x-1]*power[y-x+1]+mod*mod)%mod;
	long long hash2=(hashb[v]-hashb[u-1]*power[v-u+1]+mod*mod)%mod;
	return (hash1==hash2);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b;
    n=a.size(),m=b.size();
    a=' '+a,b=' '+b;
    create_hash();
    int l=n,r=1;
    while (l>=1&&r<=m) {
    	if (check(l,n,1,r)) res=r;
    	l--;
    	r++;
    }
    a.erase(0,1);
    b.erase(0,res+1);
    cout<<a<<b;
}