#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    float a[1000000];
    float b[1000000];
    int dem=1;
    int ts[1000000];
    int ms[1000000];
    a[0]=0;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (__gcd(j,i)==1) {
                a[dem]=(float)j/i;
                ts[dem]=j;
                ms[dem]=i;
                dem++;
            }
        }
    }
    for (int i=0;i<dem;i++) {
        b[i]=a[i];
    }
    sort(b,b+dem);
    float kq=b[k-1];
    int vt;
    for (int i=0;i<dem;i++) {
        if (a[i]==kq)
            vt=i;
    }
    cout<<ts[vt]<<"/"<<ms[vt];
}
