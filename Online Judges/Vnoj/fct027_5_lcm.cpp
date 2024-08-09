#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,t;
int a,b,d[N+5],c[N+5];
vector<int>p;
long long mod=1e9+7;
void seive() {
	iota(d,d+N+5,0);
	for (int i=2;i*i<=N;i++) {
		if (i==d[i]) {
			
			for (int j=i*i;j<=N;j+=i) 
				if (i<d[j]) d[j]=i;
		}
	}
	for (int i=2;i<=N;i++) {
		if (i==d[i]) p.push_back(i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>t;	
    while (t--) {
    	long long res=1;
    	for (auto x:p) c[x]=0;
    	cin>>a>>b;
    	for (int i=a;i<=b;i++) {
    		int temp=i;
    		while (temp>1) {
    			int div=d[temp];
    			while (temp%div==0) {
    				temp/=div;
    				c[div]++;
    			}
    		}
    	}
    	for (auto x:p) {
    		res*=2*c[x]+1;
    		res%=mod;
    	}
    	cout<<res<<'\n';
    }
}