#include <bits/stdc++.h>
using namespace std;
int main() {
    short n1,n2;
    cin>>n1>>n2;
    for (short i=n1; i<=n2;i++) {
        if ((i==6)||(i==28)||(i==496)||(i==8128)||(i==33550336)||(i==8589869056)) {
            cout<<i<<" ";
        }
    }
}
