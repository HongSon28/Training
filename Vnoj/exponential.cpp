#include<bits/stdc++.h>
using namespace std;
bool check(unsigned k) {
    for (unsigned b=1;b<k;b++) {
        for (unsigned n=2;n<=k/b;n++) {
            if (pow(b,n)==k) {
                return true;
            }
        }
    }
    return false;
}
int main () {
    int x;
    cin>>x;
    for (int k=x;k>=1;k--) {
        if (check(k)==true) {
            cout<<k;
            break;
        }
    }
}
