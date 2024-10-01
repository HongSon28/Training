#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=21;
int n;
int a[N+5],k[N+5];
int mx[M+1][(1<<M)+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>k[i];
    for (int i=1;i<=n;i++) {
    	int cur=0;
		int se=(a[i]&((1<<10)-1)),fi=(a[i]>>10);
    	for (int mask=0;mask<(1<<10);mask++) {
    		int dif=__builtin_popcount(mask^se);
    		if (k[i]-dif>=0&&k[i]-dif<=20) cur=max(cur,mx[k[i]-dif][(fi<<10)+mask]);
    	}
    	res=max(res,cur+1);
    	for (int mask=0;mask<(1<<10);mask++) {
    		int dif=__builtin_popcount(mask^fi);
    		mx[dif][(mask<<10)+se]=max(mx[dif][(mask<<10)+se],cur+1);
    	}
    	//cout<<fi<<' '<<se<<' '<<cur+1<<endl;
    }
    cout<<res;
}