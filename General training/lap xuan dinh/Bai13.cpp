#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    cin>>n;
    unsigned int tang=0;
    unsigned int block=1;
    while (n>=block) {
        tang=tang+1;
        n=n-block;
        block=block+tang+1;
    }
    cout<<tang;
}

