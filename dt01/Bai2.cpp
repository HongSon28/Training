#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("Doanconm.inp");
    ofstream out("Doanconm.out");
    int n;
    inp>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        inp>>a[i];
    }
    int mx=INT_MIN;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n+i;j++) {
            if (j>=n) {
                sum+=a[j-n];
            } else {
                sum+=a[j];
            }
            mx=max(mx,sum);
        }
    }
    out<<mx;
}
