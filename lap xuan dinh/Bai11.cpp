#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    int vitri=0;
    cin>>n;
    int a[n];
    for (int i=0; i<n;i++) {
        cin>>a[i];
    }
    for (int i=0; i<n; i++) {
        if (a[i]==1) {
            vitri=vitri+1;
        }
        if (a[i]==2) {
            vitri=vitri-1;
        }
    }
    cout<<abs(vitri);
}
