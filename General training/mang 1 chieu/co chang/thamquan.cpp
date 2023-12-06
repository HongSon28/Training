#include<bits/stdc++.h>
using namespace std;
bool comp (int a, int b) {
    return a>b;
}
int main() {
    int n,m;
    cin>>n>>m;
    int d[n],v[m];
    for (int i=0;i<n;i++)
        cin>>d[i];
    for (int i=0;i<m;i++)
        cin>>v[i];
    sort(d,d+n,comp);
    sort(v,v+m);
    int res=0;
    for (int i=0;i<n;i++) {
        res+=d[i]*v[i];
    }
    cout<<res;
}
