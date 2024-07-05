#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,m,a[N+5],b[N+5],l=1,r=1e18,res;
bool check(int d){
    int x=-d,cnt=0;
    for(int i=1;i<=m;i++){
    	if (x+d>b[i]) continue;
    	x=max(x+d,a[i]);
    	cnt++;
        while (x+d<=b[i]){
            x+=d;
            cnt++;
        }
        
    }
    if(cnt>=n) return true;
    else return false;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
    while(l<=r){
        int m=(l+r)/2;
        if(check(m)){
            res=m;
            l=m+1;
        }else r=m-1;
    }
    cout<<res;
}