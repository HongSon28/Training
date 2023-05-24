#include<bits/stdc++.h>
using namespace std;
int tongcs(int a) {
    int tong=0;
    while (a!=0) {
        tong+=a%10;
        a/=10;
    }
    return tong;
}
int main() {
    int n;
    cin>>n;
    while (tongcs(n)%4!=0) {
        n+=1;
    }
    cout<<n;
}
