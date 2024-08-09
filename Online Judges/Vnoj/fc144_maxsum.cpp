#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,res;
int b[N+5];
int main() {
    cin>>n;
    for (int i=1;i<n;i++) cin>>b[i];
    b[0]=b[n]=INT_MAX;
    for (int i=1;i<=n;i++) res+=min(b[i],b[i-1]);
    cout<<res;
}
