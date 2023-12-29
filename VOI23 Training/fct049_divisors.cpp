#include<bits/stdc++.h>
using namespace std;
const int N=431;
vector<long long>cnt(N+5);
int n,k;
void update(int x,int val) {
	for (int i=2;i<=x;i++) {
		int temp=i;
		for (int j=2;j*j<=temp;j++) {
			while (temp%j==0) {
				temp/=j;
				cnt[j]+=val;
			}
		}
		if (temp!=1) cnt[temp]+=val;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (cin>>n>>k) {
    	for (int i=1;i<=n;i++) cnt[i]=0;
    	update(n,1);
    	update(k,-1);
    	update(n-k,-1);
    	long long res=1;
    	for (int i=2;i<=n;i++) res*=cnt[i]+1;
    	cout<<res<<'\n';
    }
}