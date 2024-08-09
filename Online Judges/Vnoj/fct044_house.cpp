#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int c[N+5],mx[N+5];
int res=INT_MIN;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        mx[i]=max(mx[i-1],c[i]);
    }
    for (int i=2;i<=n;i++)
        res=max(res,mx[i-1]-c[i]);
    if (res<=0) cout<<"Lo nang roi!";
    else cout<<res;
}
