#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<int>s;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i=0;i<n;i++) {
        if (s.count(-a[i])==0) {
            cout<<-a[i];
            return 0;
        }
    }
}
