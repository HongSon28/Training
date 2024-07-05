#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
int n,a[N+5],f[N+5],mx[N+5],t;
bool p[N+5];
void sang() {
    memset(p,true,sizeof(p));
    for(int i=2;i<=N;i++)
        if(p[i])
            for(int j=i*2;j<=N;j+=i) p[j]=false;
}
int main(){
    sang();
    cin>>n;
    fill(f,f+n+1,1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=2;j*j<=a[i];j++){
            if(p[j] && a[i]%j==0) f[i]=max(f[i],mx[j]+1);
            if(a[i]%j==0 && p[a[i]/j]) f[i]=max(f[i],mx[a[i]/j]+1);
        }
        if (p[a[i]]) f[i]=max(f[i],mx[a[i]]+1);
        for(int j=2;j*j<=a[i];j++){
            if(p[j] && a[i]%j==0) mx[j]=max(f[i],mx[j]);
            if(a[i]%j==0 && p[a[i]/j]) mx[a[i]/j]=max(f[i],mx[a[i]/j]);
        }
        if (p[a[i]]) mx[a[i]]=max(mx[a[i]],f[i]);
    }
    for(int i=1;i<=n;i++) t=max(t,f[i]);
    cout<<n-t;
}