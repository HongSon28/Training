#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    short dem=0;
    cin>>n;
    unsigned long long a[n];
    for (short i=0;i<n;i++) {
        cin>>a[i];
    }
    for (short i=0;i<n-1;i++) {
        for (short j=i+1;j<n;j++) {
            if(a[i]>2*a[j])
                dem+=1;
        }
    }
    cout<<dem;
}
