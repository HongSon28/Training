#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k,res;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int i=1;
    while (i<n) {
    	res++;
    	i+=k-1;
    }
    cout<<res;
}