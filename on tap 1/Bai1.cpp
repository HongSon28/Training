#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long tong=0;
    for (int i=1;i<=n;i+=2) {
        tong+=i*i;
    }
    cout<<tong;
}
