#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,s;
long long f[N+4],w[105],v[103];
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    fill(f+1,f+N+5,1e18);
    for(int i=1;i<=n;i++)
        for(int j=N;j>=0;j--)
            if(f[j]+w[i]<=s) f[j+v[i]]=min(f[j+v[i]],f[j]+w[i]);
    for(int i=N;i>=0;i--){
        if(f[i]!=1e18){
            cout<<i;
            return 0;
        }
    }
}