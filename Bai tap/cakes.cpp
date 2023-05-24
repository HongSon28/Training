#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,kq=0,sum=0;
    cin>>n>>t;
    int a[n+2]={},b[n+2]={};
    priority_queue < int > q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<n;i++){
        int cnt=q.size();
        sum+=a[i]-a[i-1]+b[i];
        q.push(b[i]);
        kq=max(kq,cnt);
        while(sum>t && !q.empty()){
             sum-=q.top();
             q.pop();
        }
    }
    cout<<kq;
}
