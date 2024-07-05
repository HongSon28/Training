#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q,r;
double p;
priority_queue<int,vector<int>,greater<int>>pq;
int res;
int cur;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>r>>q>>p;
    cur=q;
    for (int i=1;i<=r;i++) {
    	int u,v;
    	cin>>u>>v;
    	while (!pq.empty()&&pq.top()<=u) {
    		pq.pop();
    		cur++;
    	}
    	if (cur==0) res++;
    	else {
    		cur--;
    		pq.push(v);
    	}
    }
    double temp=(double)res/r*100;
    cout<<r-res<<'/'<<r<<": ";
    if (temp>p) cout<<"Yes";
    else cout<<"No";
}