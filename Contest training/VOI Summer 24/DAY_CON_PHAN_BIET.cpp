#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+1];
bitset<N+1>mask,cur;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    mask.set(0);
    for (int i=1;i<=n;i++) {
    	cur=mask;
    	cur<<=a[i];
    	mask|=cur;
    }	
    cout<<mask.count();
}