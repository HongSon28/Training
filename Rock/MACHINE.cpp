#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n;
pair<int,int>p[N+5];
int mx[N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first>>p[i].second;
    	mx[p[i].first]=max(mx[p[i].first],p[i].second-p[i].first);
    }
    for (int i=N;i>=1;i--) mx[i]=max(mx[i],mx[i+1]);
    for (int i=1;i<=n;i++) res=max(res,mx[p[i].second+1]+p[i].second-p[i].first);
    cout<<res;
}