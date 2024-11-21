#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int a[N+5],b[N+5];
int sa[N+5],sb[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sa[i]=sa[i-1]+a[i];
    }	
    for (int i=1;i<=n;i++) {
    	cin>>b[i];
    	sb[i]=sb[i-1]+b[i];
    }
    
}