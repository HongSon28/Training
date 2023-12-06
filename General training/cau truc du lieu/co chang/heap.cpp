#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<int>s;
    int temp;
    for (int i=0;i<n;i++) {
        cin>>temp;
        s.insert(temp);
    }
    for (auto i:s) cout<<i<<' ';
}
