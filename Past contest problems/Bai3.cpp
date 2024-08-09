#include<bits/stdc++.h>
using namespace std;
int giaithua(int k) {
    if(k==1) {
        return 1;
    } else {
        return giaithua(k-1)*k;
    }
}
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    int n;
    inp>>n;
    long long a[n];
    for (int i=0; i<n; i++) {
        inp>>a[i];
    }
    unsigned kq=0;
    for (int i=0; i<n; i++) {
        if ((giaithua(a[i]-1)%a[i]==0)||(a[i]=1)) {
            kq=kq+1;
        }
    }
    out<<kq;
    inp.close();
    out.close();
}
