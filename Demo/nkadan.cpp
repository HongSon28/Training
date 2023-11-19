
#include <bits/stdc++.h>
using namespace std;
int n,mx;
int a[5005],s[5005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int l,r;
    for(int m=1;m<n;m++){
        l=m,r=m+1;
        while(l>=1 && r<=n){
            if(a[m]-a[l-1]<a[r]-a[m]) l--;
            else if(a[m]-a[l-1]>a[r]-a[m]) r++;
            else{
                mx=max(r-l+1,mx);
                cout<<l<<' '<<r<<endl;
                l--;
                r++;
            }
        }
    }
    cout<<mx;
}
