#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],mx,res=-1;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--) {
    	if (mx<a[i]) {
    		mx=a[i];
    		res++;
    	}
    }
    cout<<res;
}