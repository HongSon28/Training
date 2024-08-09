#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long h[N+5];
long long sum,res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>h[i];
        sum+=h[i];
    }
    for (int i=1;i<=n;i++) res+=(sum-h[i])*h[i];
    cout<<res/2;
}
