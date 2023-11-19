#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,k;
int a[N+5];
vector<int>v;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<k;i++) v.push_back(a[i]);
    for (int i=k+1;i<=n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
}
