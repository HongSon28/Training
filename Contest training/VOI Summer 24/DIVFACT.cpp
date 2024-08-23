#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n;
int p[N+5];
long long f[N+5],res;
vector<int>pr;
void seive() {
	for (int i=1;i<=N;i++) p[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (p[i]==i) {
			for (int j=i*i;j<=N;j+=i) 
				if (p[j]>i) p[j]=i;
		}
	}
	for (int i=2;i<=N;i++) 
		if (p[i]==i)
			pr.emplace_back(i);
}
int cnt(int x,int k) {
	int ans=0;
	while (x%k==0) {
		x/=k;
		ans++;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    seive();
    for (auto i:pr) {
    	f[i]=i;
    	int cur=0;
    	for (long long j=(long long)i*i;j<=N;j*=i) {
    		if (cur>0) {
    			f[j]=f[j/i];
    			cur--;
    		}
    		else {
    			//cout<<j<<' '<<j/i<<' '<<f[j/i]<<' '<<i<<endl;
    			f[j]=f[j/i]+i;
    			cur=cnt(f[j],i)-1;
    		}
    	}
    }
    for (int i=2;i<=n;i++) {
    	if (f[i]!=0) {
    		res+=f[i];
    		//cout<<i<<' '<<f[i]<<endl;
    		continue;
    	}
    	int j=i;
    	while (j>1) {
    		int div=p[j];
    		int cur=1;
    		while (j%div==0) {
    			j/=div;
    			cur*=div;
    		}
    		f[i]=max(f[i],f[cur]);
    	}
    	//cout<<i<<' '<<f[i]<<endl;
    	res+=f[i];
    }
    cout<<res;
}