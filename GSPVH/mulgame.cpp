#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
bool dp[N+5];
void prep() {
	dp[1]=false;
	for (int i=2;i<=N;i++) {
		for (int j=2;j<=9;j++) {
			int t=(i+j-1)/j;
			if (!dp[t]) {
				dp[i]=true;
				break;
			}
		}
	}
}
map<int,bool>dp2;
bool solve(int n) {
	if (n<=N) return dp[n];
	if (dp2.find(n)!=dp2.end()) return dp2[n];
	for (int i=2;i<=9;i++) {
		int t=(n+i-1)/i;
		if (!solve(t)) return dp2[n]=true;
	}
	return dp2[n]=false;
}
int main() {
	freopen("mulgame.inp","r",stdin);
	freopen("mulgame.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    int t,n;
    cin>>t;
    prep();
    while (t--) {
    	cin>>n;
    	if (solve(n)) cout<<"La premiere joueuse gagne."<<'\n';
    	else cout<<"La deuxieme joueuse gagne."<<'\n';
    }
}