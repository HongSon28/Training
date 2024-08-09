#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
long long x[N+5],y[N+5];
int farthest[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) continue;
            long long temp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if (temp>cur) {
                cur=temp;
                farthest()
            }
        }
    }
}
