#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if (a+b>c&&b+c>a&&c+a>b) {
        if (a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a) {
            cout<<"vuong";
        } else if (a==b&&b==c) {
            cout<<"deu";
        } else if (a==b||b==c||c==a) {
            cout<<"can";
        } else {
            cout<<"thuong";
        }
    } else {
        cout<<"khong la 3 canh tam giac";
    }
}
