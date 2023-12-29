#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
pair<int,int>p[N+5];
long long cnt,res=1,mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first;
    	p[i].second=0;
    }
    for (int i=n+1;i<=n*2;i++) {
    	cin>>p[i].first;
    	p[i].second=1;
    }
    sort(p+1,p+1+2*n);
    for (int i=1;i<=n*2;i++)  {
	    if (p[i].second==0) {
	    	if (cnt<0) {
	    		res*=(-cnt);
	    		res%=mod;
	    	}
	    	cnt++;
	    } else {
	    	if (cnt>0) {
	    		res*=cnt;
	    		res%=mod;
	    	}
	    	cnt--;
	    }
    }
    cout<<res;
}