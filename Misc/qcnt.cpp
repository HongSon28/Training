#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e5;
int n,q,res,l,r,k;
int a[N+5];
vector<int>v[N+5];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    while(q--){
        cin>>l>>r>>k;
        int lo=0,hi=v[k].size()-1,resl=-1,resr=-1;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(v[k][m]>=l){
                resl=m;
                hi=m-1;
            }else lo=m+1;
        }
        lo=0,hi=v[k].size()-1;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(v[k][m]<=r){
                resr=m;
                lo=m+1;
            }else hi=m-1;
        }
        if (resl==-1||resr==-1) cout<<0<<'\n';
        else cout<<resr-resl+1<<'\n';
    }
}