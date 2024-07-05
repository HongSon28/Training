#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<pair<int,int>>v;
priority_queue<pair<int,int>>pq;
queue<int>q;
int main() {
	freopen("TENNIS.INP","r",stdin);
	freopen("TENNIS.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	pq.push({a[i],i});
    }
    while (!pq.empty()) {
    	pair<int,int>t=pq.top();
    	pq.pop();
    	for (int i=1;i<=t.first;i++) {
    		q.push(pq.top().second);
    		a[pq.top().second]--;
    		v.push_back({t.second,pq.top().second});
    		pq.pop();
    	}
    	while (!q.empty()) {
    		if (a[q.front()]!=0) pq.push({a[q.front()],q.front()});
    		q.pop();
    	}
    }
    for (auto [x,y]:v) cout<<x<<' '<<y<<'\n';
}