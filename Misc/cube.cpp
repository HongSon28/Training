#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a[n+1]={};
        int mx=0;
        for(int i=2;i<=n;i++){
            int div=2;
            int j=i;
            while(j>1){
                if(j%div==0) {
                    a[div]++;
                    j/=div;}
                else div++;
                mx=max(mx,div);
            }
        }
        for(int i=2;i<=mx;i++) cout<<a[i]<<" ";
    }
}
