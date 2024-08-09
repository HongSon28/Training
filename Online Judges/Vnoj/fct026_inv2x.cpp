#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
long long a[N+5];
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (a[i]>2*a[j]) res++;
        }
    }
    cout<<res;
}
