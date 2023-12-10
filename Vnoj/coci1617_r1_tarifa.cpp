#include<bits/stdc++.h>
using namespace std;
const int N=100;
int x,n,cur,p[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>n;
    for (int i=1;i<=n;i++)cin>>p[i];
    for (int i=1;i<=n;i++) {
    	cur+=x;
    	cur-=p[i];
    }	
    cout<<cur+x;
}