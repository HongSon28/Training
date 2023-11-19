#include<bits/stdc++.h>
using namespace std;
int a[int(1e5)+4];
int n,s;
int main(){
    freopen("MINNUM.INP","r",stdin);
    freopen("MINNUM.OUT","w",stdout);
    cin>>n>>s;
    a[1]=1, a[n]=9;
    if(n==1) cout<<s;
    if(a[1]+a[n]>s){
        while(a[1]+a[n]>s) a[n]--;
        for(int i=2;i<n;i++) a[i]=0;
    }
    else {
        if(a[1]+a[n]<s-9*(n-2)){
            while(a[1]+a[n]<s-9*(n-2)){
                a[1]++;
            }
        }
        s-=a[n]+a[1];
        for(int i=n-1;i>=2;i--){
            if(s>=10){
                a[i]=9;
                s-=a[i];
            }
            else if(s<=9 && s>=0){
                a[i]=s;
                s-=a[i];
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i];
}
