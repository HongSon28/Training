#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t;
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
    cin>>t;
    while (t--) {
    	int j;
    	cin>>j;
    	long long res=1;
    	while (j>1) {
    		int div=d[j],cnt=0;
    		while (j%div==0) {
    			j/=div;
    			cnt++;
    		}
    		res*=cnt+1;
    	}
    	cout<<res<<'\n';
    }	
}