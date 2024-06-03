#include<bits/stdc++.h>
using namespace std;
int n,a[55],s,mn=1e9;
bool f[55][1003][1003];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=0;x<=s;x++){
            for(int z=0;z<=s;z++){
                f[i][x][z]|=f[i-1][x][z];
                if(x>=a[i]) f[i][x][z]|=f[i-1][x-a[i]][z];
                if(z>=a[i]) f[i][x][z]|=f[i-1][x][z-a[i]];
            }
        }
    }
    for(int x=0;x<=s;x++)
        for(int z=0;z<=s;z++)
            if(f[n][x][z] && x>=s-x-z&& s-x-z>=z) mn=min(mn,x-z);
    cout<<mn;
}