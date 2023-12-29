#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) cout<<(a[i]^a[j])<<' ';
    	cout<<'\n';
    }
}