#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N+5],pos[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]]=i;
	}
	int mx=1,cur=1;
	for (int i=1;i<n;i++) {
		if (pos[i]<pos[i+1]) cur++;
		else {
			mx=max(mx,cur);
			cur=1;
		}
	}
	mx=max(mx,cur);
	cout<<n-mx;
}