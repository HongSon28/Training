#include<bits/stdc++.h>
using namespace std;
int main() {
    long unsigned n;
    cin>>n;
    long unsigned thapphan=0;
    unsigned dem=0;
    unsigned du;
    while (n>0) {
        du=(n%10);
        thapphan=thapphan+du*pow(2,dem);
        dem=dem+1;
        n=n/10;
    }
    cout<<thapphan;
}
