#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int n,t;
long long a[N+5],res;
priority_queue<long long,vector<long long>,greater<long long>>pq;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	res=0;
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		pq.push(a[i]);
    	}
    	for (int i=1;i<n;i++) {
    		long long x=pq.top();
    		pq.pop();
    		long long y=pq.top();
    		pq.pop();
    		res+=x+y;
    		pq.push(x+y);
    	} 
    	pq.pop();
    	cout<<res<<'\n';
    }
}