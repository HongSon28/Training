#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int cnt[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	cnt[a[i]]++;
    }
    for (int i=N;i>=1;i--) {
    	int cur=0;
    	for (int j=i;j<=N;j+=i) {
    		cur+=cnt[j];
    		if (cur>=2) break;
    	}
    	if (cur>=2) {
    		cout<<i;
    		return 0;
    	}
    }
}