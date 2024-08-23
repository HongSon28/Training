#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
bool vis[N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	if (vis[i]||a[i]==i) continue;
    	int pos=i,cnt=0;
    	while (true) {
    		pos=a[pos];
    		vis[pos]=true;
    		cnt++;
    		if (pos==i) break;
    	}
    	res+=cnt-1;
    }
    cout<<res;
}