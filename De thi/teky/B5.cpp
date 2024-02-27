#include<bits/stdc++.h>
using namespace std;
long long a[3];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if (a[0]+a[1]<=a[2]) {
    	long long t=a[2]-a[1]-a[0];
    	cout<<t+1;
    } else cout<<0;
}