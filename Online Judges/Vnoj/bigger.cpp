#include<bits/stdc++.h>
using namespace std;
int main() {
    int dem=0;
    int a,b;
    cin>>a>>b;
    while (a<=b) {
        a*=3;
        b*=2;
        dem+=1;
    }
    cout<<dem;
}
