#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long mod=1e9+7;
int t,n,d;
int w[N+5];
string s[N+5];
int cnt[51][26];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>w[i];
    	cin>>d;
    	memset(cnt,0,sizeof(cnt));
    	for (int i=1;i<=d;i++) {
    		cin>>s[i];
    		cnt[s[i].size()][s[i][0]-'a']++;
    	}
    	long long res=0;
    	for (int i=1;i<=d;i++) {
    		if (s[i].size()!=n) continue;
    		long long cur=1;
    		cnt[s[i].size()][s[i][0]-'a']--;
    		for (int j=1;j<=n;j++) {
    			cur*=cnt[w[j]][s[i][j-1]-'a'];
    			cur%=mod;
    			cnt[w[j]][s[i][j-1]-'a']--;
    		}
    		res+=cur;
    		if (res>=mod) res-=mod;
    		cnt[s[i].size()][s[i][0]-'a']++;
    		for (int j=1;j<=n;j++) 
    			cnt[w[j]][s[i][j-1]-'a']++;
    	}
    	cout<<res<<'\n';
    }
}