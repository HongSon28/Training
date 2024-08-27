#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
int n;
int c[N+5];
long long res;
int d[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) 
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n;
    for (int i=1;i<=n;i++) {
    	int j=i;
    	int cur=1;
    	while (j>1) {
    		int div=d[j],cnt=0;
    		while (j%div==0) {
    			j/=div;
    			cnt++;
    		}
    		if (cnt&1) cur*=div;
    	}
    	res+=c[cur]*(c[cur]-1)/2;
    	c[cur]++;
    }
    cout<<res;
}