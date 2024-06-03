#include <bits/stdc++.h>
using namespace std;
const int N=1505;
int h,v,x[N+5],y[N+5],cnt;
vector<int>vx,vy;
int main(){
    cin>>h>>v;
    for(int i=1;i<=h;i++) cin>>x[i];
    for(int i=1;i<=v;i++) cin>>y[i];
    for(int i=1;i<h;i++)
        for(int j=i+1;j<=h;j++) vx.push_back(x[j]-x[i]);
    for(int i=1;i<v;i++)
        for(int j=i+1;j<=v;j++) vy.push_back(y[j]-y[i]);
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for(auto i:vx){
        int l=0,r=vy.size()-1,le=0,ri=0;
        while(l<=r){
            int m=(l+r)/2;
            if(i<=vy[m]){
                le=m;
                r=m-1;
            }else l=m+1;
        }
        l=0,r=vy.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(i>=vy[m]){
                ri=m;
                l=m+1;
            }else r=m-1;
        }
        if (i==vy[le]&&i==vy[ri]) cnt+=ri-le+1;
    }
    cout<<cnt;
}