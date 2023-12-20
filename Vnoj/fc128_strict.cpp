#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
map<int,long long>mp;
long long mod=1e9+7,res=1;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	mp[a[i]]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
    	res*=i->second+1;
    	res%=mod;
    }
    cout<<res;
}