#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long lim=1e18;
long long Rand() {
	return rd()%lim+1;
}
int n;
long long a[N+5],b[N+5],sa[N+5],sb[N+5],val[N+5];
map<long long,bool>mp;
map<long long,int>cnt;
long long ha,hb,hs;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	while (val[i]==0||mp[val[i]]) val[i]=Rand();
    }
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) {
    	sa[i]=(sa[i-1]^val[a[i]]);
    	sb[i]=(sb[i-1]^val[b[i]]);
    	hs^=val[i];
    }
    ha=sa[n],hb=sb[n];
    long long resa=0,resb=0;
    for (int i=1;i<=n;i++) {
    	cnt[sa[i-1]^sb[i-1]]++;
    	resa+=cnt[(ha^hs^sa[i]^sb[i])];
    	resb+=cnt[(hb^hs^sa[i]^sb[i])];
    }
    if (ha==hb) cout<<resa;
    else cout<<resa+resb;
}