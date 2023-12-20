#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x;
int c[N+5],d[N+5];
void seive() {
	iota(d,d+N+5,0);
	for (int i=2;i*i<=N;i++) 
		if (d[i]==i)
			for (int j=i*i;j<=N;j+=i)
				if (i<d[j]) d[j]=i;
}
int main() {
	seive();
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	memset(c,0,sizeof(c));
    	bool flag=false;
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>x;
    		while (x>1) {
    			int div=d[x];
    			while (x%div==0) {
    				x/=div;
    				c[div]++;
    			} 
    		}
    	}
    	for (int i=1;i<=n;i++) {
    		cin>>x;
    		while (x>1) {
    			int div=d[x];
    			while (x%div==0) {
    				x/=div;
    				c[div]--;
    			} 
    		}
    	}
    	for (int i=1;i<=N;i++) {
    		if (c[i]<0&&i!=2&&i!=5) {
    			flag=true;
    			break;
    		}
    	}
    	if (flag) cout<<"repeating"<<'\n';
    	else cout<<"finite"<<'\n';
    }
}