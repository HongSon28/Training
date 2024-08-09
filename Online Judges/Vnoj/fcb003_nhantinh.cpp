#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (a[1]>=2) {
    	cout<<"NO";
    	return 0;
    }
    for (int i=2;i<=n;i++) {
    	int ta=a[i],tn=i;
    	for (int j=2;j*j<=tn;j++) {
    		while (tn%j==0) {
    			tn/=j;
    			ta/=a[j];
    		}
    		if (ta!=a[tn]) {
    			cout<<"NO";
    			return 0;
    		}
    	}
    }
    cout<<"YES";
}