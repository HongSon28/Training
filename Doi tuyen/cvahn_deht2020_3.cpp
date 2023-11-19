#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,cur,res;
long long a[N+5];
long long c[2][N+5];
int main() {
    cin>>n;
    c[1][0]=1;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==1) cur++;
        else cur--;
        if (cur>0) {
            res+=c[1][cur];
            c[1][cur]++;
        } else if (cur<0) {
            res+=c[0][-cur];
            c[0][-cur]++;
        } else {
            res+=c[1][0];
            c[1][0]++;
        }
    }
    cout<<res;
}
