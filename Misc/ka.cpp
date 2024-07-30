#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,a[N+5],b[N+5],res;
void rec(int cur, int kx, int ky, int d){
	if (kx==3||ky==3) return;
    if(d==n+1){
        res=max(res,cur);
        return;
    }
    rec(cur+b[d],0,ky+1,d+1);
    rec(cur+a[d],kx+1,0,d+1);
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    rec(0,0,0,1);
    cout<<res;
}