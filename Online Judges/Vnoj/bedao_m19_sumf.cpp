#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
string s;	
long long mod=1e9+9;
int cnt0[N+5],cnt1[N+5],cntq[N+5];
long long pw[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k>>s;
    s=' '+s;
    pw[0]=1;
    for (int i=1;i<=n;i++) {
    	cnt0[i]=cnt0[i-1];
    	cnt1[i]=cnt1[i-1];
    	cntq[i]=cntq[i-1];
    	if (s[i]=='0') cnt0[i]++;
    	else if (s[i]=='1') cnt1[i]++;
    	else cntq[i]++;
    	pw[i]=pw[i-1]*2;
    	pw[i]%=mod;
    }	
    for (int i=1;i+k-1<=n;i++) {
    	if (cnt0[i+k-1]-cnt0[i-1]>0) continue;
    	res+=pw[cntq[n]-cntq[i+k-1]+cntq[i-1]];
    	res%=mod;
    }
    cout<<res;
}