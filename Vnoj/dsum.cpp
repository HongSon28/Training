#include<iostream>
using namespace std;
int main() {
    short a;
    short tong=0;
    cin>>a;
    while (a!=0) {
        tong+=a%10;
        a/=10;
    }
    cout<<tong;
}
