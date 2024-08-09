#include<bits/stdc++.h>
using namespace std;
int main() {
    int mx=0;
    for (int i=0;i<=100000;i++) {
        mx=max(mx,i*(100000-i));
    }
    cout<<mx;
}
