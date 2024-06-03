#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,a[N+5],l=1,r=1,mx;
vector<int>v;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    while(l<=r && r<=n){
        if(a[r]-a[l]<=k) r++;
        else{
            l++;
            mx=max(mx,r-l+1);
        }
    }
    l++;
    mx=max(mx,r-l+1);
    cout<<mx;
}