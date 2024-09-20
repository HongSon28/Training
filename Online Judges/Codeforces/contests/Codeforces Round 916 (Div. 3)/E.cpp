#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long a[N+5],b[N+5];
struct dat{
	long long x,y;
	bool operator < (const dat &other) const {
		return x+y<other.x+other.y;
	}
};
priority_queue<dat>pq;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=1;i<=n;i++) cin>>b[i];
    	for (int i=1;i<=n;i++) pq.push({a[i],b[i]});
    	long long x=0,y=0;
    	for (int i=1;i<=n;i++) {
    		//cout<<pq.top().x<<' '<<pq.top().y<<endl;
    		if (i%2==1) x+=pq.top().x-1;
    		else y+=pq.top().y-1;
    		pq.pop();
    	}
    	cout<<x-y<<'\n';
    }
}