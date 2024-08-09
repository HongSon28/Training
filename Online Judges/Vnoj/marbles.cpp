#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n;
    cin>>n;
    unsigned block=1;
    while (n>=block) {
        n-=block;
        block+=1;
    }
    if (n==0) {
        cout<<"Yes.";
    } else {
        cout<<"No.";
    }
}
