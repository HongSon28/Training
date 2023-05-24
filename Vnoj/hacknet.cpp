#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int s[n];
    for (int i=0;i<n;i++) {
        cin>>s[i];
    }
    sort(s,s+n);
    cout<<(s[n-1]-s[1])*(s[n-2]-s[0]);
}
