#include<bits/stdc++.h>
using namespace std;
int dem0(int x) {
    unsigned y;
    int n = 32;
    y = x >> 16;
    if (y != 0) {
        n = n - 16;
        x = y;
    }
    y = x >> 8;
    if (y != 0) {
        n = n - 8;
        x = y;
    }
    y = x >> 4;
    if (y != 0) {
        n = n - 4;
        x = y;
    }
    y = x >> 2;
    if (y != 0) {
        n = n - 2;
        x = y;
    }
    y = x >> 1;
    if (y != 0)
        return n - 2;
    return n - x;
}
int main() {
    ifstream inp("so.inp");
    ofstream out("so.out");
    int n,k;
    cin>>n>>k;
    int st=pow(2,k);
    int res=0;
    if (st<=n) {
        res=1;
        for (int i=st+1;i<=n;i++) {
            if (dem0(i)==k) {
                res++;
                cout<<i<<endl;
            }
        }
    }
    cout<<res;
}
