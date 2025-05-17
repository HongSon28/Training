#include<bits/stdc++.h>
using namespace std;
int t;
long long l,r;
long long dp[19][4][2];
int a[19];
long long f(int i,int cnt,bool les) {
	if (cnt>3) return 0;
	if (i==19) return 1;
	if (dp[i][cnt][les]!=-1) return dp[i][cnt][les];
	long long sum=0;
	int lim=9;
	if (!les) lim=a[i];
	for (int x=0;x<=lim;x++) sum+=f(i+1,cnt+(x!=0),les|(x<a[i]));
	//cout<<i<<' '<<cnt<<' '<<les<<' '<<sum<<endl;
	return dp[i][cnt][les]=sum;
}
long long calc(long long x) {
	memset(dp,-1,sizeof(dp));
	memset(a,0,sizeof(a));
	int pos=18;
	while (x>0) {
		a[pos]=x%10;
		x/=10;
		pos--;
	}
	return f(0,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>l>>r;
    	cout<<calc(r)-calc(l-1)<<'\n';
    }
}