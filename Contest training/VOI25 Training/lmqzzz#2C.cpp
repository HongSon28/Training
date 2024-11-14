#include<bits/stdc++.h>
using namespace std;
long long l,r;
vector<long long>cur,temp;
map<long long,int>mp;
void prep() {
	for (int i=1;i<=9;i++) cur.push_back(i);
	for (int i=2;i<=18;i++) {
		temp.clear();
		for (auto x:cur) 
			for (int j=1;j<=9;j++) temp.push_back(x*j);
		for (auto x:temp) cur.push_back(x);
		sort(cur.begin(),cur.end());
		cur.resize(unique(cur.begin(),cur.end())-cur.begin());
	}
	sort(cur.begin(),cur.end());
	while (cur.back()>(long long)1e10) cur.pop_back();
	for (int i=0;i<(int)cur.size();i++) mp[cur[i]]=i;
}
const int N=10000;
string s;
int n;
pair<long long,int> dp[20][2][N+5][2];
long long mem[20][N+5];
int tim;
long long f(int i,bool les,int mul,bool nz) {
	if (i==n) return (mul==mp[1]&&nz);
	if (dp[i][les][mul][nz].second==tim) return dp[i][les][mul][nz].first;
	if (les&&nz&&mem[n-i][mul]!=-1) return mem[n-i][mul];
	int lim=9;
	if (!les) lim=s[i]-'0';
	long long ans=0;
	if (!nz) ans+=f(i+1,(les|(0<s[i]-'0')),mul,0);
	for (int c=1;c<=lim;c++) {
		if (cur[mul]%c==0)ans+=f(i+1,(les|(c<s[i]-'0')),mp[cur[mul]/c],1);
	}
	//cout<<i<<' '<<les<<' '<<mul<<' '<<cur[mul]<<' '<<nz<<' '<<ans<<endl;
	dp[i][les][mul][nz]=make_pair(ans,tim);
	if (les&&nz) mem[n-i][mul]=ans;
	return ans;
}
long long calc(long long x) {
	long long ans=0;
	for (auto t:cur) {
		if (t>x) break;
		tim++;
		s=to_string(x/t);
		n=s.size();
		//cout<<t<<' '<<s<<' '<<n<<' '<<ans<<endl;
		ans+=f(0,0,mp[t],0);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    memset(mem,-1,sizeof(mem));
    //cout<<cur.size()<<endl;
    cin>>l>>r;
    cout<<calc(r)-calc(l-1);
}