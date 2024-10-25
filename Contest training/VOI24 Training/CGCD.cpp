#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
long long n,m;
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
    cin>>n>>m;
    long long res=n*m;
    for (int i=2;i<=min(n,m);i++) {
    	int j=i;
    	int cnt=0;
    	bool flag=true;
    	while (j>1) {
    		int div=d[j];
    		cnt++;
    		j/=div;
    		if (j%div==0) {
    			flag=false;
    			break;
    		}
    	}
    	if (!flag) continue;
    	if (cnt&1) res-=(n/i)*(m/i);
    	else res+=(n/i)*(m/i);
    }
    cout<<res;
}