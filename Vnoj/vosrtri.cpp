#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int>p[N+5];
long long c1[N+5],c2[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first>>p[i].second;
    	c1[p[i].first]++;
    	c2[p[i].second]++;
    }
    for (int i=1;i<=n;i++) res+=(c1[p[i].first]-1)*(c2[p[i].second]-1);
	cout<<res;
}