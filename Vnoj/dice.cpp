#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long a=n%6, b=n/6;
    cout<<b+7-a<<' '<<n*6;
}
