#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
multiset<long long>s;
long long a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<long long>());
    for (int i=1;i<=m;i++) s.insert(0);
    for (int i=1;i<=n;i++) {
    	long long t=*s.begin();
    	s.erase(s.begin());
    	s.insert(t+a[i]);
    }
    cout<<*s.rbegin();
}