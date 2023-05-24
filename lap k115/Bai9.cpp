#include <bits/stdc++.h>
using namespace std;
bool check(unsigned n) {
    for (int i =2; i<=sqrt(n);i++) {
        if (n%i==0)
            return false;
    }
    return true;
}
int main() {
    unsigned int N;
    cin>>N;
    unsigned int dem=1;
    for(int j=3;j<=N;j++) {
        if (check(j)==true) {
            dem=dem+1;
        }
    }
    cout<<dem;
}
