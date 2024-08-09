#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int sum[N+5];
int a[N+5];
int s[N+5];
int cnt[3][3];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]%=3;
		sum[i]=(sum[i-1]+a[i])%3;
	}
	cnt[0][0]=1;
	for (int i=1;i<=n;i++) {
		s[i]=(s[i-1]+a[i]*sum[i-1])%3;
		if (s[i]==0) {
			if (sum[i]==0) res+=cnt[0][0]+cnt[0][1]+cnt[0][2];
			else if (sum[i]==1) res+=cnt[1][2]+cnt[2][1]+cnt[0][0];
			else res+=cnt[0][0]+cnt[1][1]+cnt[2][2];
		} else if (s[i]==1) {
			if (sum[i]==0) res+=cnt[1][0]+cnt[1][1]+cnt[1][2];
			else if (sum[i]==1) res+=cnt[0][1]+cnt[1][0]+cnt[2][2];
			else res+=cnt[0][2]+cnt[1][0]+cnt[2][1]; 
		} else {
			if (sum[i]==0) res+=cnt[2][0]+cnt[2][1]+cnt[2][2];
			else if (sum[i]==1) res+=cnt[0][2]+cnt[1][1]+cnt[2][0];
			else res+=cnt[0][1]+cnt[1][2]+cnt[2][0];
		} 
		int x=s[i]-sum[i]*sum[i];
		x=(x%3+3)%3;
		int y=sum[i]%3;
		cnt[x][y]++;
		//cout<<res<<' '<<s[i]<<' '<<sum[i]<<' '<<x<<' '<<y<<endl;
	}
	cout<<res;
}