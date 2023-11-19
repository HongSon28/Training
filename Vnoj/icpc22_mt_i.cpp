#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5];
long long c[5];
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]%5]++;
    }
    res+=c[0]*(c[0]-1)*(c[0]-2)/6; //0 0 0
    res+=c[0]*c[1]*c[4];           //0 1 4
    res+=c[0]*c[2]*c[3];           //0 2 3
    res+=c[1]*(c[1]-1)/2*c[3];     //1 1 3
    res+=c[1]*c[2]*(c[2]-1)/2;     //1 2 2
    res+=c[2]*c[4]*(c[4]-1)/2;     //2 4 4
    res+=c[3]*(c[3]-1)/2*c[4];     //3 3 4
    cout<<res;
}
