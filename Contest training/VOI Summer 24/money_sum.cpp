#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e5;
int n;
int x[N+5];
bool dp[M+5];
int mod=1e9+7;
vector<int>res;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    dp[0]=true;
    for (int i=1;i<=n;i++)
	    for (int s=M;s>=1;s--) 
	    	 if (s>=x[i]&&dp[s-x[i]]) dp[s]=true; 
	for (int i=1;i<=M;i++)
		if (dp[i]) res.push_back(i);
	cout<<res.size()<<'\n';
	for (auto i:res) cout<<i<<' ';
}