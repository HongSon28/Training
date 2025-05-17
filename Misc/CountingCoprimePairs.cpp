#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) {
			for (int j=i*i;j<=N;j+=i) d[j]=min(d[j],i);
		}
	}
}
long long res=0;
int cnt[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	vector<int>v;
    	while (a[i]>1) {
    		int div=d[a[i]];
    		v.push_back(div);
    		while (a[i]%div==0) a[i]/=div;
    	}
    	int k=v.size();
    	for (int mask=1;mask<(1<<k);mask++) {
    		int cur=1;
    		for (int j=0;j<k;j++) {
    			if (mask>>j&1) cur*=v[j];
    		}
    		if (__builtin_popcount(mask)%2==1) res+=cnt[cur];
    		else res-=cnt[cur];
    		cnt[cur]++;
    	}
    }
    cout<<1ll*n*(n-1)/2-res;
}