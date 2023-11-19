#include<bits/stdc++.h>
using namespace std;
int m,n,c1,c2;
int main() {
    cin>>m;
    while (m--) {
        cin>>n;
        while (n%2==0) {
            c1++;
            n/=2;
        }
        while (n%5==0) {
            c2++;
            n/=5;
        }
    }
    cout<<min(c1,c2);
}
