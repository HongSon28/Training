#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll a,b,k;
ll mul(ll x,ll y){
    if(y==0) return 0;
    ll temp=mul(x,y/2);
    if(y%2==0) return (temp+temp)%b;
    return (temp+temp+x)%b;
}
ll pow(ll x,ll y){
    if(y==0) return 1;
    ll temp=pow(x,y/2);
    temp=mul(temp,temp)%b;
    if(y%2==0) return temp%b;
    return mul(temp,x)%b;
}
int main(){
    cin>>a>>b>>k;
    ll x=pow(10,(k-1));
    cout<<10*mul(a,x)/b;
}
