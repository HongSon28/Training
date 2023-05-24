#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    int dem=1,chia=2;
    while (n!=1) {
        if (n%chia==0) {
            int temp=0;
            while (n%chia==0) {
                temp++;
                n/=chia;
            }
            dem*=temp+1;
        } else {
            chia++;
        }
    }
    cout<<dem;
}

