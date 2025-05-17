#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
vector<int>cprs;
struct BIT{
	long long bit[N+5];
	void update(int idx,long long val) {
		while (idx>0) {
			bit[idx]+=val;
			idx-=(idx&(-idx));
		}
	}
	long long get(int idx) {
		long long ans=0;
		while (idx<=N) {
			ans+=bit[idx];
			idx+=(idx&(-idx));
		}
		return ans;
	}
} b1,b2;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cprs.push_back(a[i]);
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    for (int i=1;i<=n;i++) {
    	res+=b2.get(a[i]+1);
    	b2.update(a[i],b1.get(a[i]+1));
    	b1.update(a[i],1);
    }
    cout<<res;
}