#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+5],l[N+5],r[N+5];
int n,b;
long long kq;
stack<int>st1,st2;
int main(){
    freopen("NUMMAX.INP", "r", stdin);
    freopen("NUMMAX.OUT", "w", stdout);
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!st1.empty() && a[st1.top()]<=a[i]) st1.pop();
        if(!st1.empty()){
            l[i]=st1.top();
            st1.push(i);
        }
        else{
            st1.push(i);
            l[i]=0;
        }
    }
    for(int i=n;i>=1;i--){
        while(!st2.empty() && a[st2.top()]<a[i]) st2.pop();
        if(!st2.empty()){
            r[i]=st2.top();
            st2.push(i);
        }
        else{
            st2.push(i);
            r[i]=n+1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==b){
            kq+=(i-l[i])*(r[i]-i);
        }
    }
    cout<<kq;
}

