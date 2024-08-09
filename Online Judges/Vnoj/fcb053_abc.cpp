#include<bits/stdc++.h>
using namespace std;
long long n,res;
int main() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int j=1;
        while (i*j<n) {
            j++;
            res++;
        }
    }
    cout<<res;
}
