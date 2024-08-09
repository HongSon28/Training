#include<bits/stdc++.h>
using namespace std;
long long n;
int res=9;
int main() {
    cin>>n;
    while (n>=10) {
        n++;
        res++;
        if (n%10==0) n/=10;
    }
    cout<<res;
}
