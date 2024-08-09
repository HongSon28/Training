#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int res[N+5];
pair<int,int>d[N+5],p[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>d[i].first;
    	d[i].second=i;
    }
    for (int i=1;i<=m;i++) cin>>p[i].first>>p[i].second;
    sort(d+1,d+1+n);
    for (int i=1;i<=n;i+=2) res[d[i].second]=1;
    cout<<m<<'\n';
    for (int i=1;i<=n;i++) {
    	if (res[i]) cout<<"C";
    	else cout<<"S";
    } 	
}