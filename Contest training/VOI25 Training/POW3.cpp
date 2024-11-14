#include<bits/stdc++.h>
using namespace std;
const int M=2e4,N=1e3;
int t,k;
int n;
string l,r,x,y,s;
string div3(string s) {
	string ans;
	int rem=0;
	for (auto i:s) {
		rem*=10;
		rem+=(i-'0');
		ans+=to_string(rem/3);
		rem%=3;
	}
	while (ans[0]=='0') ans.erase(0,1);
	if (ans.empty()) ans="0";
	return ans;
}
int mod3(string s) {
	int ans=0;
	for (auto i:s) ans+=(i-'0');
	ans%=3;
	return ans;
}
int mod=1e9+7;
int mem[M+5][N+5];
int dp[M+5][N+5][2];
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int f(int i,int sum,bool les) {
	if (sum>k) return 0;
	if (i==n) return 1;
	if (les&&mem[n-i][k-sum]!=-1) return mem[n-i][k-sum];
	if (dp[i][sum][les]!=-1) return dp[i][sum][les];
	int lim=2;
	if (!les) lim=s[i]-'0';
	int ans=0;
	for (int c=0;c<=lim;c++) {
		int temp=f(i+1,sum+c,les|(c<s[i]-'0'));
		add(ans,temp);
		//cout<<i<<' '<<sum<<' '<<les<<' '<<i+1<<' '<<sum+c<<' '<<(les|(c<s[i]-'0'))<<' '<<ans<<' '<<temp<<endl;
	}
	//cout<<i<<' '<<sum<<' '<<les<<' '<<ans<<endl;
	if (les) mem[n-i][k-sum]=ans;
	return dp[i][sum][les]=ans;
}
int calc(string t) {
	n=t.size();
	s=t;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=k;j++)
			dp[i][j][0]=dp[i][j][1]=-1;
	//cout<<n<<' '<<t<<endl;
	return f(0,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(mem,-1,sizeof(mem));
    cin>>t;
    while (t--) {
    	cin>>l>>r>>k;
    	for (int i=l.size()-1;i>=0;i--) {
    		if (l[i]=='0') {
    			l[i]='9';
    			continue;
    		}
    		l[i]--;
    		break;
    	}
    	x.clear(),y.clear();
    	while (l!="0") {
    		x+=to_string(mod3(l));
    		l=div3(l);
    	}
    	if (x.empty()) x="0";
    	reverse(x.begin(),x.end());
    	while (r!="0") {
    		y+=to_string(mod3(r));
    		r=div3(r);
    	}
    	if (y.empty()) y="0";
    	reverse(y.begin(),y.end());
    	//cout<<x<<' '<<y<<endl;
    	cout<<((calc(y)-calc(x))%mod+mod)%mod<<'\n';
    }
}