#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,a[N+5],b[N+5],res,l=1,r=1,c[N+5];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    while (b[a[l]]==0&&l<=n) {
    	l++;
    	r++;
    }
    c[a[l]]++;
    while(l<=n){
        if(c[a[r+1]]==b[a[r+1]] || r==n){
            res=max(res,r-l+1);
            l++;
            if (l>r) {
            	r=l;
            	c[a[l]]++;
            }
            c[a[l-1]]--;
        }else{
            r++;
            c[a[r]]++;
        }
    }
    cout<<res;
}