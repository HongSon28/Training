#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long dif=a[2]-a[1];
    for (int i=3;i<=n;i++) {
    	if (dif!=(a[i]-a[i-1])) {
    		cout<<"NO";
    		return 0;
    	}
    }	
    cout<<"YES";
}