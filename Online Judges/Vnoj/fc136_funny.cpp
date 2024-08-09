#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n;
int a[N+5];
long long res;
long long c[2][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cur=0;
    c[0][0]=1;
    for (int i=1;i<=n;i++) {
    	cur^=a[i];
    	res+=c[i%2][cur];
    	c[i%2][cur]++;
    }
    cout<<res;
}