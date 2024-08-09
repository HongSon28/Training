#include<bits/stdc++.h>
using namespace std;
const int nm=1e6;
int i,n,a[nm],dp[nm],kq=(int)-1e9;
int main() {
    ifstream inp;
    inp.open("C:\\Users\\admin\\Desktop\\input.txt");
    ofstream out;
    out.open("C:\\Users\\admin\\Desktop\\output.txt");
    int n;
    inp>>n;
    for (i=0;i<n;i++) {
        inp>>a[i];
    }
    dp[0]=a[0];
    for (i=1;i<n;i++) {
        dp[i]=min(a[i],dp[i-1]);
    }
    for (i=0;i<n;i++) {
        kq=max(kq,a[i]-dp[i]);
    }
    out<<kq;
    inp.close();
    out.close();
}
