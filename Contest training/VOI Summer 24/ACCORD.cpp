#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n;
vector<int>a,cur;
map<vector<int>,long long>mp;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    a.resize(5);
    for (int i=1;i<=n;i++) {
		for (int j=0;j<5;j++) cin>>a[j];
    	sort(a.begin(),a.end());
    	for (int mask=1;mask<32;mask++) {
    		cur=a;
    		for (int j=0;j<5;j++) {
    			if (!(mask>>j&1)) cur[j]=0;
    		}
    		sort(cur.begin(),cur.end());
    		if (__builtin_popcount(mask)%2) res+=mp[cur];
    		else res-=mp[cur];
    		mp[cur]++;
    	}
    }	
    cout<<(long long)n*(n-1)/2-res;
}