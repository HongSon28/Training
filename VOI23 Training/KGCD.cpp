#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
long long N,k;
long long gt[maxn+5],cur[maxn+5],cnt[maxn+5];
long long mod=1e9+7,res;
vector<vector<int>>d(maxn+5);
void prep() {
	gt[0]=1;
	for (int i=1;i<=N;i++) {
		gt[i]=gt[i-1]*i;
		gt[i]%=mod;
	}
	for(int i=N;i>=1;i--){
    	for(int j=i;j<=N;j+=i){
    		d[j].push_back(i);
    	}
    }
}
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	if (y==0) return 1;
	long long k=power(x,y/2);
	k*=k;
	k%=mod;
	if (y%2==1) k=(k*x)%mod;
	return k;
}
long long divi(long long x,long long y) {
	return (x*power(y,mod-2))%mod;
}
long long P(long long k,long long n) {
	if (n<k) return 0;
	return divi(gt[n],gt[n-k]);
}
void add(int val){
	for(int q:d[val]){
		res-=(cur[q]*q)%mod;
		res=(res%mod+mod)%mod;
	}
	for(int i=(int)d[val].size()-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if(d[val][j]%d[val][i]==0){
				cur[d[val][i]]+=cur[d[val][j]];
				cur[d[val][i]]%=mod;
			}
		}
	}
	for(int q:d[val]){
		//cout<<val<<' '<<q<<' '<<cur[q]<<' '<<cnt[q]<<' '<<P(k,cnt[q])<<endl;
		cur[q]-=P(k,cnt[q]);
		cur[q]=(cur[q]%mod+mod)%mod;
		cur[q]+=P(k,++cnt[q]);
		cur[q]%=mod;
		//cout<<val<<' '<<q<<' '<<cur[q]<<' '<<cnt[q]<<' '<<P(k,cnt[q])<<endl;
	}
	for(int i=0;i<d[val].size();i++){
		for(int j=i+1;j<d[val].size();j++){
			if(d[val][i]%d[val][j]==0){
				cur[d[val][j]]-=cur[d[val][i]];
				cur[d[val][j]]=(cur[d[val][j]]%mod+mod)%mod;
			}
		}
	}
	for(int q:d[val]){
		res+=(cur[q]*q)%mod;
		res%=mod;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>N>>k;
	prep();
	for (int n=1;n<=N;n++) {
		add(n);
		if (n>=k) cout<<res<<'\n';
	}
}