#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=1e6;
int n;
long long a[N+5],b[N+5];
int res;
long long m;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) {
	return rd()%(r-l+1)+l;
}
vector<long long>p;
bool pp[M+5],used[M+5];
void seive() {
	memset(pp,true,sizeof(pp));
	for (int i=2;i*i<=M;i++) {
		if (pp[i]) for (int j=i*i;j<=M;j+=i) pp[j]=false;
	}
	for (int i=2;i<=M;i++) if (pp[i]) p.push_back(i);
}
void calc(long long t) {
	if (t==2) return;
	if (t<=M&&used[t]) return;
	if (t<=M) used[t]=true;
	for (int i=1;i<=n;i++) b[i]=a[i]%t;
	sort(b+1,b+1+n);
	int cur=1;
	for (int i=2;i<=n;i++) {
		if (b[i]==b[i-1]) cur++;
		else cur=1;
		if (res<cur) {
			res=cur;
			m=t;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    seive();
    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	res+=a[i]%2;
    }
    res=max(res,n-res),m=2;
    for (int t=1;t<=100;t++) {
    	int i=Rand(1,n-1),j=Rand(i+1,n);
    	long long cur=abs(a[i]-a[j]);
    	for (auto div:p) {
    		if (cur%div!=0) continue;
    		calc(div);
    		while (cur%div==0) cur/=div;
    		if (cur==1) break;
    	}
    	if (cur!=1) calc(cur);
    }
    cout<<res<<'\n';
    vector<pair<long long,int>>v;
    for (int i=1;i<=n;i++) v.push_back({a[i]%m,i});
    sort(v.begin(),v.end());
    int cur=1;
    for (int i=1;i<(int)v.size();i++) {
    	if (v[i].first==v[i-1].first) cur++;
    	else cur=1;
    	if (cur==res) {
    		for (int j=i-cur+1;j<=i;j++) cout<<v[j].second<<' ';
    		return 0;
    	}
    }
}