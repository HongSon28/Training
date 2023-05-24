#include<bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin>>t;
    string a[t/2];
    long long i=0, chia=2;
    while (t!=1) {
        while (t%chia==0) {
            a[i]=to_string(chia);
            i++;
            t/=chia;
        }
        chia++;
    }
    for (int b=0;b<i-1;b++) {
        for (int c=b+1;c<i;c++) {
            if (a[c]+a[b]>a[b]+a[c])
                swap(a[b],a[c]);
        }
    }
    for (int j=0;j<i;j++) {
        cout<<a[j];
    }
}
