#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    cout<<(min(a[0],a[1]))*(min(a[2],a[3]));
}
