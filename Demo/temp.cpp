#include<bits/stdc++.h>
using namespace std;
bool check(long long a) {
    for (int i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
int main() {
    long long n;
    cin>>n;
    if (check(n)==true) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}

