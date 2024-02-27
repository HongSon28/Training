#include<bits/stdc++.h>
using namespace std;
const int N=11000;
int n;
vector<int>v;
bool p[N+5];
long long sum[N+5];
void seive() {
	v.push_back(0);
	memset(p,true,sizeof(p));
	for (int i=2;i<=N;i++) {
		if (p[i]) {
			v.push_back(i);
			for (int j=i*i;j<=N;j+=i) p[j]=false;
		}
	}
	for (int i=1;i<(int)v.size();i++) sum[i]=sum[i-1]+v[i];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    while (cin>>n) {
    	if (n==0) return 0;
    	int res=0;
    	for (int i=1;i<(int)v.size();i++) {
    		if (v[i]>n) break;
    		int lo=i,hi=v.size()-1,ans=-1;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (sum[mid]-sum[i-1]>n) hi=mid-1;
    			else if (sum[mid]-sum[i-1]<n) lo=mid+1;
    			else {
    				ans=mid;
    				break;
    			}
    		}
    		if (ans!=-1) res++;
    	}
    	cout<<res<<'\n';
    }	
}