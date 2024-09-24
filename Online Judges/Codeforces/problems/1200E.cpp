#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=1e6;
int n;
string s[N+5];
vector<long long>hs1[N+5];
vector<long long>hs2[N+5];
long long base1=311,mod1=1e9+7;
long long base2=317,mod2=1e9+11;
long long power1[M+5],power2[M+5];
int cur=0;
void prep() {
	power1[0]=power2[0]=1;
	for (int i=1;i<=M;i++) {
		power1[i]=power1[i-1]*base1%mod1;
		power2[i]=power2[i-1]*base2%mod2;
	}
}
void create(int id,int pos) {
	if (hs1[id].empty()) {
		hs1[id].resize(1);
		hs2[id].resize(1);
	}
	while (pos<(int)s[id].size()) {
		long long cur=(hs1[id].back()*base1+(int)s[id][pos])%mod1;
		hs1[id].push_back(cur);
		cur=(hs2[id].back()*base2+(int)s[id][pos])%mod2;
		hs2[id].push_back(cur);
		pos++;
	}
}
pair<long long,long long> get(int id,int l,int r) {
	return make_pair((hs1[id][r]-hs1[id][l-1]*power1[r-l+1]+mod1*mod1)%mod1,
					 (hs2[id][r]-hs2[id][l-1]*power2[r-l+1]+mod2*mod2)%mod2);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		s[i]=' '+s[i];
		create(i,1);
	}
	prep();
	s[0]+=s[1];
	cur=s[0].size();
	create(0,1);
	for (int i=2;i<=n;i++) {
		int ans=0;
		for (int len=1;len<=min((int)s[i].size(),cur);len++) {
			//cout<<cur<<' '<<cur-len+1<<' '<<get(i,1,len)<<' '<<get(0,cur-len+1,cur)<<endl;
			if (get(i,1,len)==get(0,cur-len,cur-1)) ans=len;
		}
		s[i].erase(0,ans+1);
		s[0]+=s[i];
		//cout<<ans<<' '<<s[i]<<' '<<s[0]<<endl;
		create(0,cur);
		cur=s[0].size();
	}
	s[0].erase(0,1);
	cout<<s[0];
}