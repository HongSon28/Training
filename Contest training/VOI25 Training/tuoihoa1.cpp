#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],b[N+5],m;
priority_queue<pair<double,int>>pq;
double calc(double x,double y) {
	return x/y-x/(y+1);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	b[i]=1;
    	pq.push({calc(a[i],1),i});
    }
    m-=n;
    while (m--) {
    	int i=pq.top().second;
    	pq.pop();
    	b[i]++;
    	pq.push({calc(a[i],b[i]),i});
    }
    double res=0;
    for (int i=1;i<=n;i++) {
    	res+=(double)a[i]/(double)b[i];
    }
    cout<<fixed<<res;
}