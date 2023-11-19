#include <iostream>
using namespace std;
int main() {
    freopen("LED.INP","r",stdin);
    freopen("LED.OUT","w",stdout);
    int n;
    cin >> n;
    if (n==2) {
        cout<<1;
        return 0;
    }
    if (n%3==0) cout << (n/3)*7;
    else if (n%3==1) cout << (n/3-1)*7+4;
    else cout << (n/3)*7+1;
}
